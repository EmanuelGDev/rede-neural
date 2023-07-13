#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

//Variaveis usadas
double X[4][10] = {
  {1, -1, -1, 1, -1, 1, 1, -1, -1, 1},
  {1, -1, -1, -1, 1, -1, 1, -1, 1, 1},
  {1, 1, -1, -1, -1, 1, 1, -1, 1, -1},
  {-1, -1, -1, 1, -1, 1, 1, 1, -1, 1}
};

double aprender[4][4];
double W[4][10];
double cossenoNumerador[10];
double cossenoDenominador[10];
double cossenoDenominador2[10];
double qualid[10];
double soma = 0;

//Funções de calculo usadas
void calc1();
void calc2();
void calc3();
void calc4();

//Funções de imprimir usadas
void imp1();
void imp2();
void imp3();
void imp4();
void imp5();


int main(){
  calc1();
  calc2();
  calc3();
  calc4();

  imp1();
  imp3();
  imp2();
  imp4();
  imp5();

  system("pause");
  return 0;
}

/* Matriz de memoria auto-associativa
Faz um produto cruzado entre a matriz dos rostos
e sua transvessa*/

void calc1(){

  for(int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      aprender[i][j] = 0;
        for(int k = 0; k < 10; k++){
          aprender[i][j] += X[i][k] * X[j][k];
        }
    }
  }
}
/*Matriz de lembraça
Faz um produto cruzado entre a matriz de memoria auto-associativa
e a matriz de rostos*/

void calc2(){
  for(int i = 0; i < 4; i++){
    for (int j = 0; j < 10; j++){
      W[i][j] = 0;
      for(int k = 0; k < 4; k++){
        W[i][j] += aprender[i][k] * X[k][j];
      }
    }
  }
}

/*Calculo do Numerador do cosseno*/

void calc3(){
  for(int i = 0 ; i < 10; i++){
    cossenoNumerador[i] = 0;
  }
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 10; j++){
      cossenoNumerador[j] += W[i][j]*X[i][j];
    }
  }
}

/*Calculo dos denominadores do cosseno*/

void calc4(){
  for(int i = 0 ; i < 10; i++){
    cossenoDenominador[i] = 0;
  }
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 10; j++){
        cossenoDenominador[j] += W[i][j]*W[i][j];
    }
  }
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 10; j++){
        cossenoDenominador2[j] += X[i][j]*X[i][j];
        }
    }
    for(int i = 0; i < 10; i++){
        cossenoDenominador[i] = sqrt(cossenoDenominador2[i]) * sqrt(cossenoDenominador[i]);
    }
}

/*Imprime os rostos iniciais*/

void imp1(){
  cout << "Rostos: \n";
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 10; j++){
      cout << setw(4) << fixed << setprecision(0) << X[i][j];
    }
      cout << endl;
  }
  cout << endl;
}

/*Imprime os rostos armazenados na matriz de memoria
auto-associativa*/

void imp3(){
  cout << "Matriz dos rostos armazenados na memoria auto-associativa:\n";
  for(int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cout << setw(5) << fixed << setprecision(0) << aprender[i][j];
    }
    cout << endl;
  }        
  cout << endl;
}

/*Imprime a matriz de rostos após lembrança*/

void imp2(){
  cout << "Matriz apos ser feita a lembraça dos rostos:\n";
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 10; j++){
        cout << setw(8) << fixed << setprecision(0) << W[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

/*Imprime valores dos numeradores e denominadores do cosseno*/

void imp4(){
  cout << "Numeradores dos calculos do cosseno: \n";
  for(int i = 0; i < 10; i++){
    cout << setw(4) << fixed << setprecision(0)<< cossenoNumerador[i];
  }
  cout << "\n\nDeniminadores dos calculos do cosseno: \n";
  for(int i = 0; i < 10; i++){
    cout << setw(10) << fixed << setprecision(4) << cossenoDenominador[i];
  }
  cout << endl;
}

/*Imprime a taxa de qualidade de aproveitamento de cada rosto*/
void imp5(){
  for(int i = 0; i < 10; i++){
    qualid[i] = cossenoNumerador[i]/cossenoDenominador[i];
    cout << "Qualidade da resposta para o rosto " << i+1 << ": " << fixed << setprecision(4) << qualid[i] << endl;
    soma += qualid[i];
  }
  cout << "A media da qualidade de resposta dos 10 rostos: " << fixed << setprecision(4) << soma/10 << endl;
}
