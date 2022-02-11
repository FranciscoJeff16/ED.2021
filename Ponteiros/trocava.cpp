#include <iostream>

// Implemente a função 'troca'.
void troca(int *a, int *b)
{
    int troc;
    troc=*a;
    *a=*b;
    *b=troc;
}

int main()
{
   int x, y;
   std::cin >> x;
   std::cin >> y;
   // Chame a função 'troca' para trocar os valores de x e y.
   troca(&x,&y);

   
   std::cout << x << " " << y << std::endl;
   return 0;
}