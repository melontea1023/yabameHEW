#include "Collision.h"
#include <algorithm>

using namespace DirectX::SimpleMath;

namespace Collision
{
	//==================================
	// ��CheckHit�֐�
	// ��(�����̒���)�ƕ���(�����̑傫��)�̓����蔻��
	//==================================
	bool CheckHit(const Line& line, const Plane& plane)
	{
		// �����̐��������̕��ʂɂԂ���Ȃ��̂͐��ƕ��ʂ����s�Ȏ��̂݁B
		// ���̕����x�N�g���ƕ��ʂ̖@���x�N�g��������(�����ς�0)���ǂ������`�F�b�N����
		if (Dot((plane.point - line.point), plane.normal) == 0 || Dot(line.vec, plane.normal) != 0)
		{
			return true;
		}
		return false;
	}

	//==================================
	// ��CheckHit�֐�
	// �����ƕ���(�����̑傫��)�̓����蔻��
	//==================================
	bool CheckHit(const Segment& segment, const Plane& plane)
	{
		if (Dot((segment.start - plane.point), plane.normal) * Dot((segment.end - plane.point), plane.normal) <= 0)
		{
			return true;
		}
		return false;
	}

	//==================================
	// ��CheckHit�֐�
	// ��(�����̒���)�ƃ|���S���̓����蔻��
	//==================================
	bool CheckHit(const Line& line, const Polygon& polygon)
	{
		Vector3 p;
		return CheckHit(line, polygon, p);
	}
	bool CheckHit(const Line& line, const Polygon& polygon, DirectX::SimpleMath::Vector3& contact)
	{
		// �O�p�`�̖@�����v�Z
		Vector3 normal = GetNormal(polygon);

		// ���Ɩ@�������s�ł���ꍇ
		float denom = Dot(normal, line.vec);
		if (fabs(denom) < 1e-6f) {
			return false; // �����Ȃ�
		}

		// ����̌�_���v�Z
		float d = Dot(normal, polygon.p0);
		float t = (d - Dot(normal, line.point)) / denom;
		contact = line.point + t * line.vec;

		// �O�p�`���Ɍ�_�����邩�𔻒�
		return PointInTriangle(contact, polygon);
	}

	//==================================
	// ��CheckHit�֐�
	// �����ƃ|���S���̓����蔻��
	//==================================
	bool CheckHit(const Segment& segment, const Polygon& polygon)
	{
		Vector3 p;
		return CheckHit(segment, polygon, p);
	}
	bool CheckHit(const Segment& segment, const Polygon& polygon, Vector3& contact)
	{
		Plane plane(polygon.p0, GetNormal(polygon));

		if (CheckHit(segment, plane))
		{
			// �����ƕ��ʂ̌�_�ʒu���v�Z
			float denom = Dot(plane.normal, segment.end - segment.start);
			float t = Dot(plane.normal, plane.point - segment.start) / denom;

			// t��0����1�͈͓̔��ł���ΐ����ƕ��ʂ���������
			if (t >= 0.0f && t <= 1.0f) {
				contact = segment.start + t * (segment.end - segment.start); // ��_���v�Z

				// ��_���O�p�`�|���S���̓����ɂ��邩����
				return PointInTriangle(contact, polygon);
			}
		}
		return false;

	}

	//==================================
	// ��CheckHit�֐�
	// ���̂ƕ��ʂ̓����蔻��
	//==================================
	bool CheckHit(const Sphere& sphere, const Plane& plane)
	{
		// ���̂̒��S���畽�ʂւ̋������v�Z
		float distance = DistancePointToPlane(sphere.center, plane);

		// ���̂̔��a�ȓ��Ȃ�Փ�
		return (distance <= sphere.radius);
	}

	//==================================
	// ��CheckHit�֐�
	// ���̂ƃ|���S���̓����蔻��
	//==================================
	bool CheckHit(const Sphere& sphere, const Polygon& polygon)
	{
		Vector3 p;
		return CheckHit(sphere, polygon, p);
	}
	bool CheckHit(const Sphere& sphere, const Polygon& polygon, Vector3& contact)
	{
		Plane plane(polygon.p0, GetNormal(polygon));

		// ���̂̒��S���畽�ʂւ̋������v�Z
		float distance = DistancePointToPlane(sphere.center, plane);

		// ���̂̔��a�ȓ��Ȃ�
		if (distance <= sphere.radius)
		{
			// �����ƕ��ʂ̌�_���v�Z
			contact = ProjectPointToPlane(sphere.center, plane);

			// ��_���O�p�`�|���S���̓����ɂ��邩����
			if (PointInTriangle(contact, polygon))
			{
				return true;
			}

			// ��_���O�p�`�|���S���̊O���Ȃ�e�ӂƂ̋������v�Z
			if (DistancePointToSegment(sphere.center, { polygon.p0 , polygon.p1 }, contact) <= sphere.radius)
			{
				return true;
			}

			if (DistancePointToSegment(sphere.center, { polygon.p1 , polygon.p2 }, contact) <= sphere.radius)
			{
				return true;
			}

			if (DistancePointToSegment(sphere.center, { polygon.p2 , polygon.p0 }, contact) <= sphere.radius)
			{
				return true;
			}
		}

		return false;
	}

	////==================================
	//// ��CheckHit�֐�
	//// �~���ƕ��ʂ̓����蔻��
	////==================================
	//bool CheckHit(const Cylinder& cylinder, const Plane& plane)
	//{
	//	// �~���̗��[�𕽖ʂ̖@���ɓ��e���A���̋������v�Z
	//	float distanceToTop = Dot((cylinder.top - plane.point), plane.normal);
	//	float distanceToBottom = Dot((cylinder.bottom - plane.point), plane.normal);

	//	// �~���̎��̒[�_�����ʂ̔��Α��ɂ��邩�ǂ���
	//	if ((distanceToTop * distanceToBottom) <= 0.0f)
	//	{
	//		return true; // �������ʂ����؂�
	//	}

	//	// �~���̔��a���l��������������
	//	float distanceToAxis = fabs(distanceToTop);
	//	return distanceToAxis <= cylinder.radius;
	//}

	////==================================
	//// ��CheckHit�֐�
	//// �~���ƃ|���S���̓����蔻��
	////==================================
	//bool CheckHit(const Cylinder& cylinder, const Polygon& polygon)
	//{
	//	Vector3 p;
	//	return CheckHit(cylinder, polygon, p);
	//}
	//bool CheckHit(const Cylinder& cylinder, const Polygon& polygon, Vector3& contact)
	//{
	//	Vector3 axis = cylinder.top - cylinder.bottom;

	//	// ���ʏ�ł̎O�p�`��3���_�̎ˉe���v�Z
	//	Vector3 projP0 = polygon.p0 - (axis * axis.Dot(polygon.p0 - cylinder.bottom));
	//	Vector3 projP1 = polygon.p1 - (axis * axis.Dot(polygon.p1 - cylinder.bottom));
	//	Vector3 projP2 = polygon.p2 - (axis * axis.Dot(polygon.p2 - cylinder.bottom));

	//	// ���a�̓����v�Z
	//	float radiusSq = cylinder.radius * cylinder.radius;

	//	// ��ʂƎO�p�`�̍Ŋ�_���v�Z
	//	Vector3 closestToBottom = ClosestPointOnTriangle(cylinder.bottom, { projP0, projP1, projP2 });
	//	if ((closestToBottom - cylinder.bottom).LengthSquared() <= radiusSq) {
	//		contact = closestToBottom;
	//		return true;
	//	}

	//	// ��ʂƎO�p�`�̍Ŋ�_���v�Z
	//	Vector3 closestToTop = ClosestPointOnTriangle(cylinder.top, { projP0, projP1, projP2 });
	//	if ((closestToTop - cylinder.top).LengthSquared() <= radiusSq) {
	//		contact = closestToTop;
	//		return true;
	//	}

	//	return false;
	//}


	////==================================
	//// ��CheckHit�֐�
	//// �J�v�Z���ƕ��ʂ̓����蔻��
	////==================================
	//bool CheckHit(const Capsule& capsule, const Plane& plane)
	//{
	//	// �J�v�Z���̒��S���itop �� bottom�j���`
	//	Vector3 capsuleDirection = capsule.bottom - capsule.top;

	//	float distanceToTop = Dot((capsule.top - plane.point), plane.normal);
	//	float distanceToBottom = Dot((capsule.bottom - plane.point), plane.normal);

	//	// ���S���̗��[�����ʂ̔��Α��ɂ���ꍇ�A�������Ă���
	//	if (distanceToTop * distanceToBottom <= 0.0f) {
	//		return true;
	//	}

	//	// ���[�����ʂ̓������ɂ���ꍇ�A�J�v�Z���̔��a���l��
	//	float distClosest = min(fabs(distanceToTop), fabs(distanceToBottom));
	//	return distClosest <= capsule.radius;
	//}

	////==================================
	//// ��CheckHit�֐�
	//// �J�v�Z���ƃ|���S���ƃ|���S���̓����蔻��
	////==================================
	//bool CheckHit(const Capsule& capsule, const Polygon& polygon)
	//{
	//	Vector3 p;
	//	return CheckHit(capsule, polygon, p);
	//}
	//bool CheckHit(const Capsule& capsule, const Polygon& polygon, Vector3& contact)
	//{
	//	// �����ƃ|���S���̓����蔻��
	//	Segment seg = { capsule.top, capsule.bottom };
	//	if (CheckHit(seg, polygon, contact))
	//	{
	//		return true;
	//	}

	//	// ���̂ƃ|���S���̓����蔻��
	//	Sphere sphere = { capsule.top, capsule.radius };
	//	if (CheckHit(sphere, polygon, contact))
	//	{
	//		return true;
	//	}
	//	sphere = { capsule.bottom, capsule.radius };
	//	if (CheckHit(sphere, polygon, contact))
	//	{
	//		return true;
	//	}

	//	// �e�O�p�`�̃G�b�W
	//	Vector3 edges[3][2] = {
	//		{polygon.p0, polygon.p1},
	//		{polygon.p1, polygon.p2},
	//		{polygon.p2, polygon.p0}
	//	};

	//	// �J�v�Z�������Ɗe�G�b�W�̍ŋߐړ_���v�Z
	//	for (const auto& edge : edges) {
	//		Vector3 edgeClosest = ClosestPointOnSegment(capsule.top, { edge[0], edge[1] });
	//		Vector3 capsuleClosest = ClosestPointOnSegment(edgeClosest, { capsule.top, capsule.bottom });
	//		if ((edgeClosest - capsuleClosest).LengthSquared() <= capsule.radius * capsule.radius)
	//		{
	//			contact = edgeClosest;
	//			return true;
	//		}
	//	}

	//	return false;
	//}

	//==================================
	// ��CheckHit�֐�
	// ���̂Ƌ��̂̓����蔻��
	//==================================
	bool CheckHit(Sphere sphere1, Sphere sphere2)
	{
		Vector3 p;
		return CheckHit(sphere1, sphere2, p);
	}
	bool CheckHit(Sphere sphere1, Sphere sphere2, Vector3& contact)
	{
		float len2 = (sphere1.center - sphere2.center).LengthSquared();
		float r2 = (sphere1.radius + sphere2.radius) * (sphere1.radius + sphere2.radius);
		if (r2 > len2) {

			// �ڐG�_���v�Z ��sphere1��sphere2�Ɍォ��Ԃ����ė����Ƃ��Ă���
			Vector3 v = (sphere1.center - sphere2.center);
			v.Normalize();
			contact = sphere2.center + v * sphere2.radius;

			return true;
		}
		return false;
	}

	//==================================
	// ��CheckHit�֐�
	// AABB��AABB�̓����蔻��
	//==================================
	bool CheckHit(AABB p1, AABB p2) {

		// X���W
		if (p1.max.x < p2.min.x) {
			return false;
		}

		if (p1.min.x > p2.max.x) {
			return false;
		}

		// Y���W
		if (p1.max.y < p2.min.y) {
			return false;
		}

		if (p1.min.y > p2.max.y) {
			return false;
		}

		// Z���W
		if (p1.max.z < p2.min.z) {
			return false;
		}

		if (p1.min.z > p2.max.z) {
			return false;
		}

		return true;
	}


	//=========================================================================================
	//=========================================================================================
	//=========================================================================================
	//=========================================================================================
	//=========================================================================================



	//==================================
	// ��Dot�֐�
	// �x�N�g���̓��ς����߂�
	//==================================
	float Dot(const Vector3& v1, const Vector3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	//==================================
	// ��Cross�֐�
	// �x�N�g���̊O�ς����߂�
	//==================================
	Vector3 Cross(const Vector3& v1, const Vector3& v2)
	{
		return Vector3(
			v1.y * v2.z - v1.z * v2.y, // x����
			v1.z * v2.x - v1.x * v2.z, // y����
			v1.x * v2.y - v1.y * v2.x); // z����
	}

	//==================================
	// ��ClosestPointOnSegment�֐�
	// �_��������܂ł̍ŋߒn�_
	//==================================
	Vector3 ClosestPointOnSegment(const Vector3& point, const Segment& segment)
	{
		// �����̃x�N�g�����v�Z�i�I�_ - �n�_�j
		Vector3 vec = segment.end - segment.start;

		// �����̒����̕������v�Z�i�x�N�g���̑傫����2��j
		double r2 = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;

		// �_��������̎n�_�܂ł̃x�N�g���Ƃ̓��ς��v�Z
		double tt = -Dot(vec, (segment.start - point));

		// �_���n�_���������̊O��
		if (tt < 0)
		{
			// �_�Ɛ����̎n�_�̋�����Ԃ�
			return segment.start;
		}
		// �_���I�_���������̊O���̏ꍇ
		else if (tt > r2)
		{
			// �_�Ɛ����̏I�_�Ƃ̋�����Ԃ�
			return segment.end;
		}
		// �_�������̏�ɓ��e�����ꍇ�A������̍ŒZ�������v�Z
		else
		{
			Vector3 ab = segment.end - segment.start; // �����̃x�N�g��
			float lengthSq = ab.LengthSquared(); // �����̒����̓��

			// �������މ��i���[�������_�j���Ă���ꍇ
			if (lengthSq == 0.0f) {
				return segment.start; // �����̒[�_��Ԃ�
			}

			// �_��������ɓ��e�����ʒu���v�Z�i0 <= t <= 1 �͈̔́j
			float t = (point - segment.start).Dot(ab) / lengthSq;
			t = std::clamp(t, 0.0f, 1.0f);

			// ������̍ŋߐړ_��Ԃ�
			return (segment.start + t * ab);
		}
	}

	//==================================
	// ��DistanceSquaredPointToSegment�֐�
	// �_��������܂ł̋�����2��
	//==================================
	float DistanceSquaredPointToSegment(const Vector3& point, const Segment& segment)
	{
		Vector3 p;
		return DistanceSquaredPointToSegment(point, segment, p);
	}
	float DistanceSquaredPointToSegment(const Vector3& point, const Segment& segment, Vector3& contact)
	{
		contact = ClosestPointOnSegment(point, segment);

		return (point - contact).LengthSquared();
	}

	//==================================
	// ��DistancePointToSegment�֐�
	// �_��������܂ł̋���
	//==================================
	float DistancePointToSegment(const Vector3& point, const Segment& segment)
	{
		Vector3 p;
		return DistancePointToSegment(point, segment, p);
	}
	float DistancePointToSegment(const Vector3& point, const Segment& segment, Vector3& contact)
	{
		contact = ClosestPointOnSegment(point, segment);

		return (point - contact).Length();
	}

	//==================================
	// ��DistancePointToPlane�֐�
	// �_���畽�ʂ܂ł̋���
	//==================================
	float DistancePointToPlane(const Vector3& point, const Plane& plane)
	{
		return fabs(Dot((point - plane.point), plane.normal) / Dot(plane.normal, plane.normal));
	}

	//==================================
	// ��ProjectPointToPlane�֐�
	// �_���畽�ʂɉ��낵�������̌�_
	//==================================
	Vector3 ProjectPointToPlane(const Vector3& point, const Plane& plane)
	{
		double t = -Dot((point - plane.point), plane.normal) / Dot(plane.normal, plane.normal);

		// ��_�̍��W���v�Z
		return  point + (plane.normal * t);
	}


	//==================================
	// ��PointInTriangle�֐�
	// �O�p�`�̓������ǂ����𔻒肷��
	//==================================
	bool PointInTriangle(const Vector3& point, const Polygon& polygon)
	{
		// 3�ӂ̃x�N�g��
		Vector3 ab = polygon.p1 - polygon.p0;
		Vector3 bc = polygon.p2 - polygon.p1;
		Vector3 ca = polygon.p0 - polygon.p2;

		// �����̓_�Ƃ̃x�N�g��
		Vector3 ap = point - polygon.p0;
		Vector3 bp = point - polygon.p1;
		Vector3 cp = point - polygon.p2;

		// 3�ӂƓ����̓_�Ƃ̖@���x�N�g��
		Vector3	n1 = Cross(ab, ap);
		Vector3	n2 = Cross(bc, bp);
		Vector3	n3 = Cross(ca, cp);

		// �O�p�`�̖@���x�N�g��
		Vector3	normal = Cross(ab, bc);

		float dot = n1.Dot(normal);
		if (dot < 0) return false; // �ׂ��p�x���݊p

		dot = n2.Dot(normal);
		if (dot < 0) return false; // �ׂ��p�x���݊p

		dot = n3.Dot(normal);
		if (dot < 0) return false; // �ׂ��p�x���݊p

		return true;
	}


	//==================================
	// ��ClosestPointOnTriangle�֐�
	// �_�ƎO�p�`�Ԃ̍ŋߐړ_�����߂�
	//==================================
	Vector3 ClosestPointOnTriangle(const Vector3& point, const Polygon& polygon)
	{
		Plane plane(polygon.p0, GetNormal(polygon));

		// �����ƕ��ʂ̌�_���v�Z
		Vector3 p = ProjectPointToPlane(point, plane);

		// ��_���O�p�`�|���S���̓����ɂ��邩����
		if (PointInTriangle(p, polygon))
		{
			return p;
		}

		// ��_���O�p�`�|���S���̊O���Ȃ�e�ӂƂ̋������v�Z
		Vector3 p1, p2, p3;
		float d1 = DistanceSquaredPointToSegment(point, { polygon.p0 , polygon.p1 }, p1);
		float d2 = DistanceSquaredPointToSegment(point, { polygon.p1 , polygon.p2 }, p2);
		float d3 = DistanceSquaredPointToSegment(point, { polygon.p2 , polygon.p0 }, p3);

		if (d1 < d2)
		{
			if (d1 < d3)
			{
				return p1;
			}
			else
			{
				return p3;
			}
		}
		else
		{
			if (d2 < d3)
			{
				return p2;
			}
			else
			{
				return p3;
			}
		}
	}

	//==================================
	// �@�����v�Z
	//==================================
	Vector3 GetNormal(const Polygon& polygon)
	{
		Vector3 n = Cross((polygon.p1 - polygon.p0), (polygon.p2 - polygon.p0));
		n.Normalize();
		return n;
	}

	//==================================
	// ���̂𓖂�������̒n�_�ɓ�����
	//==================================
	Vector3 moveSphere(const Segment& segment, const float& radius, const Polygon& polygon, const Vector3& contact, float& distance)
	{
		// �����̕����x�N�g��
		Vector3 direction = segment.end - segment.start;
		float length = direction.Length();
		direction.Normalize();

		// �����̒�����0�̏ꍇ�͌v�Z�s�\
		if (length == 0.0f) return segment.start;

		// �񎟕��������v�Z���� (a*t^2 + b*t + c = 0)
		float a = 1.0f; // direction�͐��K������Ă���̂�a=1
		float b = 2.0f * Collision::Dot((segment.start - contact), direction);
		float c = (segment.start - contact).LengthSquared() - radius * radius;
		float discriminant = b * b - 4.0f * a * c;

		// ���������
		if (discriminant >= 0.0f) {

			// �������߂�
			float sqrt_discriminant = std::sqrt(discriminant);
			float t1 = (-b + sqrt_discriminant) / (2.0f * a);
			float t2 = (-b - sqrt_discriminant) / (2.0f * a);

			// ������̉��𔻒�
			if (t1 < t2)
			{
				distance = t1;
				return  segment.start + t1 * direction;;
			}
			else
			{
				distance = t2;
				return  segment.start + t2 * direction;
			}
		}

		return segment.start;
	}
	Vector3 moveSphere(const Sphere& sphere, const Polygon& polygon, const Vector3& contact)
	{
		Vector3 v = sphere.center - contact;
		v.Normalize();

		return contact + v * sphere.radius;
	}



	// �����ɕ��s�ȗ^����ꂽ���̂S�p�`�̍��W�����߂�
	//void CalcQuadOrientedLine(
	//	DirectX::SimpleMath::Vector3 startpos,
	//	DirectX::SimpleMath::Vector3 endpos,
	//	DirectX::SimpleMath::Vector3* v,
	//	float width)
	//{
	//	// �����ȃx�N�g�������߂�
	//	Vector3 zaxis(0, 0, 1);
	//	Vector3 line = endpos - startpos;

	//	Vector3 ans;
	//	ans = line.Cross(zaxis); // �O��
	//	ans.Normalize(); // ���K��

	//	Vector3 startposplus = startpos + ans * width / 2.0f;
	//	Vector3 startposminus = startpos - ans * width / 2.0f;

	//	Vector3 endposplus = endpos + ans * width / 2.0f;
	//	Vector3 endposminus = endpos - ans * width / 2.0f;

	//	v[0] = startposplus;
	//	v[1] = endposplus;

	//	v[2] = startposminus;
	//	v[3] = endposminus;
	//}

	//// ���������������i�l�p�`�j�Ƌ��̓����蔻����s��
	//bool CollisionSphereOrientedQuad(
	//	Vector3 StartPos, // �J�n�ʒu
	//	Vector3 EndPos,// �I���ʒu
	//	float width, // ��
	//	float radius, // ���a
	//	Vector3 CirclePos) // ���S���W
	//{

	//	Vector3 v[4]; // �l�p�`���_
	//	Vector3 intersectionpoint{}; // ��_

	//	// �����ɕ��s�ȂS�p�`�̍��W�����߂�
	//	CalcQuadOrientedLine(StartPos, EndPos, v, width);

	//	// �����i�S�p�`�̐����j
	//	Segment s[4];
	//	s[0].startpoint = v[0];
	//	s[0].endpoint = v[1];

	//	s[1].startpoint = v[2];
	//	s[1].endpoint = v[3];

	//	s[2].startpoint = v[0];
	//	s[2].endpoint = v[2];

	//	s[3].startpoint = v[1];
	//	s[3].endpoint = v[3];


	//	float t;

	//	// �l�p�`���͂ސ����Ɠ_�̋����𒲂ׂ�
	//	for (int idx = 0; idx < 4; idx++) {
	//		// �~�̒��S�Ɛ����̋��������߂�
	//		float distance = calcPointSegmentDist(CirclePos, s[idx], intersectionpoint, t);

	//		if (distance < radius) {

	//			return true;
	//		}
	//	}

	//	return false;

	//}



	//==================================
	// AABB��ݒ�
	//==================================
	AABB SetAABB(Vector3 centerposition, float width, int height, int depth)
	{
		AABB aabb{};

		width = fabs(width);
		height = fabs(height);
		depth = fabs(depth);

		aabb.min.x = centerposition.x - width / 2.0f;
		aabb.min.y = centerposition.y - height / 2.0f;
		aabb.min.z = centerposition.z - depth / 2.0f;

		aabb.max.x = centerposition.x + width / 2.0f;
		aabb.max.y = centerposition.y + height / 2.0f;
		aabb.max.z = centerposition.z + depth / 2.0f;

		return aabb;
	}

}