#define MAXOCTREGIONS 1              /* maximum number of regions per octant */
#define MINOCTREGIONS 1              /* minimum number of regions per octant */

extern void    oct_gen_tree_from_input_data(LB *lb, int *c1, int *c2,
					    int *c3, float *c0);
extern void    oct_resetIdCount(int start_count);
extern void    oct_roots_in_order(pOctant **roots_ret,int *nroots_ret);
extern int     oct_nextId(void);
extern void    oct_terminal_refine(pOctant oct,int count);
extern pOctant oct_findId(int i);
extern pOctant oct_global_insert(pRegion region);
extern int     oct_subtree_insert(pOctant oct, pRegion region);

