#ifndef HITTABLE_H

#define HITTABLE_H

#include "../Core/Vector3.h"
#include "../Core/Ray.h"
#include "../Core/AABB.h"

#include <memory>

class Material;

struct HitRecord 
{
	Point3 hitPoint;
	Vector3 normalVector;
	std::shared_ptr<const Material> materialPtr{};
	double u{};
	double v{};
	double t{};
	bool frontFacing{};

	void setFaceNormal(const Ray& ray, const Vector3& outwardNormal)
	{
		frontFacing = dotProduct(ray.direction(), outwardNormal) < 0;
		normalVector = frontFacing ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
public:
	virtual ~Hittable() {};

	virtual bool isHit(const Ray& ray, double minT, double maxT, HitRecord& record) const = 0;
	virtual bool hasBoundingBox(double time0, double time1, AABB& boundingBox) const = 0;
	virtual Point3 getCenter() const = 0;
	virtual Point3 getOrigin() const = 0;
};

#endif // !HITTABLE_H