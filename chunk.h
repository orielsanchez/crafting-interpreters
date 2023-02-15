#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
// TODO: Devise an encoding that compresses the line information for a series
// of instructions on the same line. Change write(Chunk() to write this 
// compressed form, and implement a getLine() function that, given the index
// of an instruction, determines the line where the instruction occurs.
int addConstant(Chunk* chunk, Value value);

#endif
