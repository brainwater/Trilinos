#include "migoct_const.h"

/* static void tag_regions(pOctant *octs, int *newpids, int nocts, 
 			LB_TAG **export_tags, int *nsentags, int **tag_pids,
			LB_TAG **kept_tags, int *nkeptags); */
static void tag_regions(pOctant *octs, int *newpids, int nocts, 
			Region **export_tags, int *nsentags, int **tag_pids,
			Region **prev_tags, int *npimtags, float *c2,
			int *max_objs);

/* static void malloc_new_objects(int ntags, LB_TAG *tags, int *tag_pids,
                               int *nrectags, LB_TAG **import_tags,
			       LB_TAG *kept_tags, int nkeptags); */
static void malloc_new_objects(int nsentags, pRegion export_tags, 
			       int *tag_pids, int *nrectags,
			       pRegion *import_tags, pRegion prev_tags,
			       int npimtags, float *c3);
