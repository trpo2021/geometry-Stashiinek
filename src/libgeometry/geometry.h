#pragma once

struct circle{
  float x;
  float y;
  float radius;

  float per;
  float sq;
};

typedef struct circle circle;

void Check(char ch[], int n, circle *ln1);

void Perimeter(circle *ring);

void Square(circle *ring);

int Executes(circle *ring1, circle *ring2);
