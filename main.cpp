#include "EDD.hpp"








void iniciar(){
    tLista mazosr;
    tPila pila;
    cartas carta;
    int pos;
    //  creacion de cada valor de las cartas

    for (int i=0;i<104;i++){
        carta.estado=DESCONOCIDA;
        carta.value=(i%13)+2;
        mazosr.append(carta);
    }
    for (int i=104;i<=108;i++){
        carta.estado=DESCONOCIDA;
        carta.value=JOKER;
        mazosr.append(carta);
    }
    mazosr.print();
/*
    for (int i=0;i<108;i++)
        cout<<mazosr[i].value<<"\n";
*/

    srand(time(0));
    carta.value=0;
    for (int i=0;i<108;i++){
        pos=1+(rand()%108);
        mazosr.moveToPos(pos);
        if (mazosr.getValue().value){
            pila.push(mazosr.getValue());
            mazosr.insert(carta);
        }
        else{
            while(mazosr.getValue().value==0){
                cout<<"muere pos="<<pos<<"\n";
                pos=(pos*pos*3+pos*7+1)%108;
                mazosr.moveToPos(pos);
            }
            pila.push(mazosr.getValue());
            mazosr.insert(carta);
        }
    }
    pila.print();
}











int main(){
    iniciar();
    return 0;
}