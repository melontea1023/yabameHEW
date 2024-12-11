#pragma once

#include <simplemath.h>

namespace Collision
{
	// ���C���i�����̒����̐��j
	struct Line {
		DirectX::SimpleMath::Vector3 point; // �ʉߒn�_
		DirectX::SimpleMath::Vector3 vec; // ���̕����x�N�g��
	};

	// �v���[��(�����̍L���̕���)
	struct Plane {
		DirectX::SimpleMath::Vector3 point; // ���ʏ��1�_
		DirectX::SimpleMath::Vector3 normal; // ���ʂ̖@���x�N�g��
		//float d;         // ���ʂ̕�����: ax + by + cz + d = 0 �� d
	};

	// �Z�O�����g�i�L���̒����̐����j
	struct Segment {
		DirectX::SimpleMath::Vector3 start; // �n�_
		DirectX::SimpleMath::Vector3 end; // �I�_
	};

	// �O�p�`�|���S���i�L���̍L���̕��ʁj
	struct Polygon {
		const DirectX::SimpleMath::Vector3 p0; //���_0
		const DirectX::SimpleMath::Vector3 p1; //���_1
		const DirectX::SimpleMath::Vector3 p2; //���_2
	};

	// ����
	struct Sphere {
		DirectX::SimpleMath::Vector3 center; // ���S
		float radius; // ���a
	};

	//// �~��
	//struct Cylinder {
	//	DirectX::SimpleMath::Vector3 top; // ��
	//	DirectX::SimpleMath::Vector3 bottom; // ��
	//	float radius; // ���a
	//};

	//// �J�v�Z��
	//struct Capsule {
	//	DirectX::SimpleMath::Vector3 top; // ��̒��S 
	//	DirectX::SimpleMath::Vector3 bottom; // ��̒��S
	//	float radius; // ���a
	//};

	// BOX��`
	struct AABB {
		DirectX::SimpleMath::Vector3 min;
		DirectX::SimpleMath::Vector3 max;
	};

	//�����蔻��
	bool CheckHit(const Line& line, const Plane& plane); //��(�����̒���)�ƕ���(�����̑傫��)
	bool CheckHit(const Segment& segment, const Plane& plane); //�����ƕ���(�����̑傫��)
	bool CheckHit(const Line& line, const Polygon& polygon); //��(�����̒���)�ƃ|���S��
	bool CheckHit(const Line& line, const Polygon& polygon, DirectX::SimpleMath::Vector3& contact); //����
	bool CheckHit(const Segment& segment, const Polygon& polygon); //�����ƃ|���S��
	bool CheckHit(const Segment& segment, const Polygon& polygon, DirectX::SimpleMath::Vector3& contact); //����
	bool CheckHit(const Sphere& sphere, const Plane& plane); //���̂ƕ���(�����̑傫��)
	bool CheckHit(const Sphere& sphere, const Polygon& polygon); //���̂ƃ|���S��
	bool CheckHit(const Sphere& sphere, const Polygon& polygon, DirectX::SimpleMath::Vector3& contact); //����
	//bool CheckHit(const Cylinder& cylinder, const Plane& plane); //�~���ƕ���
	//bool CheckHit(const Cylinder& cylinder, const Polygon& polygon); //�~���ƃ|���S��
	//bool CheckHit(const Cylinder& cylinder, const Polygon& polygon, DirectX::SimpleMath::Vector3& contact); //����
	//bool CheckHit(const Capsule& capsule, const Plane& plane); //�J�v�Z���ƕ���(�����̑傫��)
	//bool CheckHit(const Capsule& capsule, const Polygon& polygon); //�J�v�Z���ƃ|���S��
	//bool CheckHit(const Capsule& capsule, const Polygon& polygon, DirectX::SimpleMath::Vector3& contact); //����
	bool CheckHit(Sphere sphere1, Sphere sphere2); //���̂Ƌ���
	bool CheckHit(Sphere sphere1, Sphere sphere2, DirectX::SimpleMath::Vector3& contact); //����
	bool CheckHit(AABB p1, AABB p2); // AABB��AABB


	//���ρE�O��
	float Dot(const DirectX::SimpleMath::Vector3& v1, const DirectX::SimpleMath::Vector3& v2);
	DirectX::SimpleMath::Vector3 Cross(const DirectX::SimpleMath::Vector3& v1, const DirectX::SimpleMath::Vector3& v2);


	DirectX::SimpleMath::Vector3 ClosestPointOnSegment(const DirectX::SimpleMath::Vector3& point, const Segment& segment);
	float DistanceSquaredPointToSegment(const DirectX::SimpleMath::Vector3& point, const Segment& segment);
	float DistanceSquaredPointToSegment(const DirectX::SimpleMath::Vector3& point, const Segment& segment, DirectX::SimpleMath::Vector3& contact);
	float DistancePointToSegment(const DirectX::SimpleMath::Vector3& point, const Segment& segment);
	float DistancePointToSegment(const DirectX::SimpleMath::Vector3& point, const Segment& segment, DirectX::SimpleMath::Vector3& contact);
	float DistancePointToPlane(const DirectX::SimpleMath::Vector3& point, const Plane& plane);
	DirectX::SimpleMath::Vector3 ProjectPointToPlane(const DirectX::SimpleMath::Vector3& point, const Plane& plane);
	bool PointInTriangle(const DirectX::SimpleMath::Vector3& point, const Polygon& polygon);
	DirectX::SimpleMath::Vector3 ClosestPointOnTriangle(const DirectX::SimpleMath::Vector3& point, const Polygon& polygon);
	DirectX::SimpleMath::Vector3 GetNormal(const Polygon& polygon);


	DirectX::SimpleMath::Vector3 moveSphere(const Segment& capsule, const float& radius, const Polygon& polygon, const DirectX::SimpleMath::Vector3& contact, float& distance);
	DirectX::SimpleMath::Vector3 moveSphere(const Sphere& sphere, const Polygon& polygon, const DirectX::SimpleMath::Vector3& contact);


	//struct Plane {
	//	DirectX::SimpleMath::Vector3 normal; // ���ʂ̖@���x�N�g��
	//	float d;         // ���ʂ̕�����: ax + by + cz + d = 0 �� d
	//};





	// make AABB
	AABB SetAABB(DirectX::SimpleMath::Vector3 centerposition, float width, int height, int depth);

/*
	// �����ɕ��s�ȗ^����ꂽ���̂S�p�`�̍��W�����߂�
	void CalcQuadOrientedLine(
		DirectX::SimpleMath::Vector3 startpos,
		DirectX::SimpleMath::Vector3 endpos,
		DirectX::SimpleMath::Vector3* v,
		float width);


	// ���������������i�l�p�`�j�Ƌ��̓����蔻����s��
	bool CollisionSphereOrientedQuad(
		DirectX::SimpleMath::Vector3 StartPos,						// �J�n�ʒu
		DirectX::SimpleMath::Vector3 EndPos,							// �I���ʒu
		float width,							// ��
		float radius,							// ���a
		DirectX::SimpleMath::Vector3 CirclePos);						// ���S���W
	*/





}