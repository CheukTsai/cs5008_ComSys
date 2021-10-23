

#ifndef INT_HELPERS_H

#define INT_HELPERS_H

void PrintInt(void* val);

// Returns 0 if equal
// Neg val if first is smaller than second
// Pos val if first is bigger than second
int CompareInt(void* first, void* second);


#endif