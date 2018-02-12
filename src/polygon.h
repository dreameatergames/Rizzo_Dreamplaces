
#ifndef POLYGON_H
#define POLYGON_H

/*
Polygon clipping routines written by Forest Hale and placed into public domain.
*/

void PolygonF_QuadForPlane(float *outpoints, float planenormalx, float planenormaly, float planenormalz, float planedist, float quadsize);
void PolygonF_Divide(int innumpoints, const float *inpoints, float planenormalx, float planenormaly, float planenormalz, float planedist, float epsilon, int outfrontmaxpoints, float *outfrontpoints, int *neededfrontpoints, int outbackmaxpoints, float *outbackpoints, int *neededbackpoints, int *oncountpointer);

#ifdef NO_DOUBLE
#define PolygonD_QuadForPlane(OUP,PNX,PNY,PNZ,PDS,QSZ) PolygonF_QuadForPlane(OUP,PNX,PNY,PNZ,PDS,QSZ)
#define PolygonD_Divide(IPS,INP,PNX,PNY,PNZ,PDS,EPS,OFM,OFP,NFP,OBM,OBP,NBP,OCP)        PolygonF_Divide(IPS,INP,PNX,PNY,PNZ,PDS,EPS,OFM,OFP,NFP,OBM,OBP,NBP,OCP)
#else
void PolygonD_QuadForPlane(double *outpoints, double planenormalx, double planenormaly, double planenormalz, double planedist, double quadsize);
void PolygonD_Divide(int innumpoints, const double *inpoints, double planenormalx, double planenormaly, double planenormalz, double planedist, double epsilon, int outfrontmaxpoints, double *outfrontpoints, int *neededfrontpoints, int outbackmaxpoints, double *outbackpoints, int *neededbackpoints, int *oncountpointer);
#endif

#endif
