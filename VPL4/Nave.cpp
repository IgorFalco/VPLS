#include "Ponto2D.hpp"
#include "Nave.hpp"
#include <iostream>
#include <cmath>

    void Nave::mover(double dx, double dy)
    {
        this -> posicao.x = posicao.x + dx;
        this -> posicao.y = posicao.y + dy;
    }; //atualiza a posição da nave nos eixos x e y somando valores dx e dy, respectivamente.

    double Nave::calcular_distancia(Nave * nave)
    {
         double d = 0;
        double dx = nave -> posicao.x - this -> posicao.x;
        double dy = nave -> posicao.y - this -> posicao.y;
        if((dx*dx - dy*dy) < 0)
            d = (dx*dx - dy*dy)*(-1);
        else
            d = (dx*dx - dy*dy);
        return sqrt(d);
    }; //calcula e retorna a distância euclidiana para outra nave qualquer passada como parâmetro (ponteiro).

    Nave* Nave::determinar_nave_mais_proxima(Nave** naves, int n)
    {
        int a;
        double *d;
        double menor = 50000;

        d = new double[n];

        for(int i = 0; i < n; i++ )
        {
            if(this == naves[i])
            {
                d[i] = 500000;
            }
                else
                {
                    double distancia = this -> calcular_distancia(naves[i]);
                    d[i] = distancia;
                }
              
            if (d[i] < menor)
            {
                menor = d[i];
                a = i;
            }
        }
        delete[] d;
            
        return naves[a];
    }; //recebe um array de ponteiros para naves e um parâmetro que informa a quantidade de elementos nesse array. Determina qual a nave mais próxima e retorna um ponteiro para essa nave.

    void Nave::atacar(Nave** naves, int n)
    {
        double dano;
        Nave* nave = this -> determinar_nave_mais_proxima(naves, n);
        for(int i = 0; i < n ; i++ )
        {
            if ((nave == naves[i]))
            {
                double d = naves[i] -> calcular_distancia(this);
                dano = (100 / d) * this -> forca;
            
                if (dano >= 30)
                    dano = 30;

                naves[i] -> energia = naves[i] -> energia - dano;
                if(naves[i] -> energia <= 50)
                    std::cout <<  "Energia baixa!" << std::endl;
                break;
            }

        };
    };  /*ataca a nave mais próxima. A nave que sofre um ataque tem o seu valor de energia reduzido, onde a quantidade de dano é dada pela equação: dano = (100/d)*forca, onde d é a distância 
        para a nave, e a força é o parâmetro informado no construtor. O máximo de dano (limite) que uma nave pode fazer em outra é 30. Se após um ataque a nave atacada tiver energia menor/
        igual a 50 deve ser impressa a mensagem "Energia baixa!".*/
    
    void Nave::imprimir_status()
    {
        std::cout << this -> posicao.x << " " << this -> posicao.y << " " << this -> energia << std::endl;
    }; //imprime a situação atual da nave no seguinte formato "x y energia".