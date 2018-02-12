
/*
Polygon clipping routines written by Forest Hale and placed into public domain.
*/

#include <stdio.h>
#include <math.h>
#include "polygon.h"

#include "qtypes.h"

void PolygonF_QuadForPlane(float *outpoints, float planenormalx, float planenormaly, float planenormalz, float planedist, float quadsize)
{
	float d, quadright[3], quadup[3];
	if (dr_fabs(planenormalz) > dr_fabs(planenormalx) && dr_fabs(planenormalz) > dr_fabs(planenormaly))
	{
		quadup[0] = 1;
		quadup[1] = 0;
		quadup[2] = 0;
	}
	else
	{
		quadup[0] = 0;
		quadup[1] = 0;
		quadup[2] = 1;
	}
	// d = -DotProduct(quadup, planenormal);
	d = -(quadup[0] * planenormalx + quadup[1] * planenormaly + quadup[2] * planenormalz);
	// VectorMA(quadup, d, planenormal, quadup);
	quadup[0] += d * planenormalx;
	quadup[1] += d * planenormaly;
	quadup[2] += d * planenormalz;
	// VectorNormalize(quadup);
	d = (float)(1.0 / dr_sqrt(quadup[0] * quadup[0] + quadup[1] * quadup[1] + quadup[2] * quadup[2]));
	quadup[0] *= d;
	quadup[1] *= d;
	quadup[2] *= d;
	// CrossProduct(quadup,planenormal,quadright);
	quadright[0] = quadup[1] * planenormalz - quadup[2] * planenormaly;
	quadright[1] = quadup[2] * planenormalx - quadup[0] * planenormalz;
	quadright[2] = quadup[0] * planenormaly - quadup[1] * planenormalx;
	// make the points
	outpoints[0] = planedist * planenormalx - quadsize * quadright[0] + quadsize * quadup[0];
	outpoints[1] = planedist * planenormaly - quadsize * quadright[1] + quadsize * quadup[1];
	outpoints[2] = planedist * planenormalz - quadsize * quadright[2] + quadsize * quadup[2];
	outpoints[3] = planedist * planenormalx + quadsize * quadright[0] + quadsize * quadup[0];
	outpoints[4] = planedist * planenormaly + quadsize * quadright[1] + quadsize * quadup[1];
	outpoints[5] = planedist * planenormalz + quadsize * quadright[2] + quadsize * quadup[2];
	outpoints[6] = planedist * planenormalx + quadsize * quadright[0] - quadsize * quadup[0];
	outpoints[7] = planedist * planenormaly + quadsize * quadright[1] - quadsize * quadup[1];
	outpoints[8] = planedist * planenormalz + quadsize * quadright[2] - quadsize * quadup[2];
	outpoints[9] = planedist * planenormalx - quadsize * quadright[0] - quadsize * quadup[0];
	outpoints[10] = planedist * planenormaly - quadsize * quadright[1] - quadsize * quadup[1];
	outpoints[11] = planedist * planenormalz - quadsize * quadright[2] - quadsize * quadup[2];
}

#ifndef NO_DOUBLE
void PolygonD_QuadForPlane(dr_real_t *outpoints, dr_real_t planenormalx, dr_real_t planenormaly, dr_real_t planenormalz, dr_real_t planedist, dr_real_t quadsize)
{
	dr_real_t d, quadright[3], quadup[3];
	if (dr_fabs(planenormalz) > dr_fabs(planenormalx) && dr_fabs(planenormalz) > dr_fabs(planenormaly))
	{
		quadup[0] = 1;
		quadup[1] = 0;
		quadup[2] = 0;
	}
	else
	{
		quadup[0] = 0;
		quadup[1] = 0;
		quadup[2] = 1;
	}
	// d = -DotProduct(quadup, planenormal);
	d = -(quadup[0] * planenormalx + quadup[1] * planenormaly + quadup[2] * planenormalz);
	// VectorMA(quadup, d, planenormal, quadup);
	quadup[0] += d * planenormalx;
	quadup[1] += d * planenormaly;
	quadup[2] += d * planenormalz;
	// VectorNormalize(quadup);
	d = 1.0 / dr_sqrt(quadup[0] * quadup[0] + quadup[1] * quadup[1] + quadup[2] * quadup[2]);
	quadup[0] *= d;
	quadup[1] *= d;
	quadup[2] *= d;
	// CrossProduct(quadup,planenormal,quadright);
	quadright[0] = quadup[1] * planenormalz - quadup[2] * planenormaly;
	quadright[1] = quadup[2] * planenormalx - quadup[0] * planenormalz;
	quadright[2] = quadup[0] * planenormaly - quadup[1] * planenormalx;
	// make the points
	outpoints[0] = planedist * planenormalx - quadsize * quadright[0] + quadsize * quadup[0];
	outpoints[1] = planedist * planenormaly - quadsize * quadright[1] + quadsize * quadup[1];
	outpoints[2] = planedist * planenormalz - quadsize * quadright[2] + quadsize * quadup[2];
	outpoints[3] = planedist * planenormalx + quadsize * quadright[0] + quadsize * quadup[0];
	outpoints[4] = planedist * planenormaly + quadsize * quadright[1] + quadsize * quadup[1];
	outpoints[5] = planedist * planenormalz + quadsize * quadright[2] + quadsize * quadup[2];
	outpoints[6] = planedist * planenormalx + quadsize * quadright[0] - quadsize * quadup[0];
	outpoints[7] = planedist * planenormaly + quadsize * quadright[1] - quadsize * quadup[1];
	outpoints[8] = planedist * planenormalz + quadsize * quadright[2] - quadsize * quadup[2];
	outpoints[9] = planedist * planenormalx - quadsize * quadright[0] - quadsize * quadup[0];
	outpoints[10] = planedist * planenormaly - quadsize * quadright[1] - quadsize * quadup[1];
	outpoints[11] = planedist * planenormalz - quadsize * quadright[2] - quadsize * quadup[2];
}
#endif

void PolygonF_Divide(int innumpoints, const float *inpoints, float planenormalx, float planenormaly, float planenormalz, float planedist, float epsilon, int outfrontmaxpoints, float *outfrontpoints, int *neededfrontpoints, int outbackmaxpoints, float *outbackpoints, int *neededbackpoints, int *oncountpointer)
{
	int i, frontcount = 0, backcount = 0, oncount = 0;
	const float *n, *p;
	dr_real_t frac, pdist, ndist;
	for (i = 0;i < innumpoints;i++)
	{
		p = inpoints + i * 3;
		n = inpoints + ((i + 1) < innumpoints ? (i + 1) : 0) * 3;
		pdist = p[0] * planenormalx + p[1] * planenormaly + p[2] * planenormalz - planedist;
		ndist = n[0] * planenormalx + n[1] * planenormaly + n[2] * planenormalz - planedist;
		if (pdist >= -epsilon)
		{
			if (pdist <= epsilon)
				oncount++;
			if (frontcount < outfrontmaxpoints)
			{
				*outfrontpoints++ = p[0];
				*outfrontpoints++ = p[1];
				*outfrontpoints++ = p[2];
			}
			frontcount++;
		}
		if (pdist <= epsilon)
		{
			if (backcount < outbackmaxpoints)
			{
				*outbackpoints++ = p[0];
				*outbackpoints++ = p[1];
				*outbackpoints++ = p[2];
			}
			backcount++;
		}
		if ((pdist > epsilon && ndist < -epsilon) || (pdist < -epsilon && ndist > epsilon))
		{
			oncount++;
			frac = pdist / (pdist - ndist);
			if (frontcount < outfrontmaxpoints)
			{
				*outfrontpoints++ = (float)(p[0] + frac * (n[0] - p[0]));
				*outfrontpoints++ = (float)(p[1] + frac * (n[1] - p[1]));
				*outfrontpoints++ = (float)(p[2] + frac * (n[2] - p[2]));
			}
			frontcount++;
			if (backcount < outbackmaxpoints)
			{
				*outbackpoints++ = (float)(p[0] + frac * (n[0] - p[0]));
				*outbackpoints++ = (float)(p[1] + frac * (n[1] - p[1]));
				*outbackpoints++ = (float)(p[2] + frac * (n[2] - p[2]));
			}
			backcount++;
		}
	}
	if (neededfrontpoints)
		*neededfrontpoints = frontcount;
	if (neededbackpoints)
		*neededbackpoints = backcount;
	if (oncountpointer)
		*oncountpointer = oncount;
}

#ifndef NO_DOUBLE
void PolygonD_Divide(int innumpoints, const dr_real_t *inpoints, dr_real_t planenormalx, dr_real_t planenormaly, dr_real_t planenormalz, dr_real_t planedist, dr_real_t epsilon, int outfrontmaxpoints, dr_real_t *outfrontpoints, int *neededfrontpoints, int outbackmaxpoints, dr_real_t *outbackpoints, int *neededbackpoints, int *oncountpointer)
{
	int i, frontcount = 0, backcount = 0, oncount = 0;
	const dr_real_t *n, *p;
	dr_real_t frac, pdist, ndist;
	for (i = 0;i < innumpoints;i++)
	{
		dr_real_t p0, p1, p2;
		dr_real_t n0, n1, n2;
		p = inpoints + i * 3;
		n = inpoints + ((i + 1) < innumpoints ? (i + 1) : 0) * 3;
		p0=p[0]; p1=p[1]; p2=p[2];
		n0=n[0]; n1=n[1]; n2=n[2];
		pdist = p0 * planenormalx + p1 * planenormaly + p2 * planenormalz - planedist;
		ndist = n0 * planenormalx + n1 * planenormaly + n2 * planenormalz - planedist;
		if (pdist >= -epsilon)
		{
			if (pdist <= epsilon)
				oncount++;
			if (frontcount < outfrontmaxpoints)
			{
				*outfrontpoints++ = p0;
				*outfrontpoints++ = p1;
				*outfrontpoints++ = p2;
			}
			frontcount++;
		}
		if (pdist <= epsilon)
		{
			if (backcount < outbackmaxpoints)
			{
				*outbackpoints++ = p0;
				*outbackpoints++ = p1;
				*outbackpoints++ = p2;
			}
			backcount++;
		}
		if ((pdist > epsilon && ndist < -epsilon) || (pdist < -epsilon && ndist > epsilon))
		{
			oncount++;
			frac = pdist / (pdist - ndist);
			if (frontcount < outfrontmaxpoints)
			{
				*outfrontpoints++ = p0 + frac * (n0 - p0);
				*outfrontpoints++ = p1 + frac * (n1 - p1);
				*outfrontpoints++ = p2 + frac * (n2 - p2);
			}
			frontcount++;
			if (backcount < outbackmaxpoints)
			{
				*outbackpoints++ = p0 + frac * (n0 - p0);
				*outbackpoints++ = p1 + frac * (n1 - p1);
				*outbackpoints++ = p2 + frac * (n2 - p2);
			}
			backcount++;
		}
	}
	if (neededfrontpoints)
		*neededfrontpoints = frontcount;
	if (neededbackpoints)
		*neededbackpoints = backcount;
	if (oncountpointer)
		*oncountpointer = oncount;
}
#endif

