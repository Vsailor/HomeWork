#define charSize 255

struct Set {
	unsigned int set[charSize];
};

extern void setEmpty(Set &a);
extern bool isEmpty(Set a);
extern void addElement(Set &a, unsigned int element);
extern void removeElement(Set &a, unsigned int element);
extern int amountOfElementEntry(Set a, unsigned int element);
extern Set unionOfSets(Set set1, Set set2);
extern Set intersectionOfSets(Set set1, Set set2);
