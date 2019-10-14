#ifndef LASMAP_H
#define LASMAP_H

#include "visualobject.h"
#include "LASLoader.h"

class LasMap : public VisualObject
{
public:
    LasMap();
    ~LasMap() override;

    virtual void init() override;
    virtual void draw() override;

    gsl::LASLoader lasloader{"../VSIMOblig/LASdata/33-1-497-327-20.las"};
    void printSomePoints();
    void addAllPointsToVertices();

    static float length(const gsl::Vector3D& a, const gsl::Vector3D& b);
    void normalizePoints();
    std::vector<gsl::Vector3D> mapToGrid(const std::vector<gsl::Vector3D>& points, int xGrid, int zGrid, gsl::Vector3D min, gsl::Vector3D max);

    void constructSurface(int x, int z);
    void readFile();
    void readFile(std::string filename);
    std::vector<gsl::Vector3D> points;
    std::vector<gsl::Vector3D> planePoints;
    //"../VSIMOblig/LASdata/33-1-497-327-20.las"

    float xMin;
    float yMin;
    float zMin;

    float xMax;
    float yMax;
    float zMax;

    float scaleFactor = 10;
};

#endif // LASMAP_H
