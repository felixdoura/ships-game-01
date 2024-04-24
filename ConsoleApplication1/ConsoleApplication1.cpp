#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Player {
    string nombre;
    int vida;
    int ataqueFisico;
    int ataqueEspecial;
    int defensa;
    int nivel;
    int exp;
};

struct Enemigo {
    string nombre;
    int vida;
    int ataque;
    int defensa;
};

struct Booster {
    string nombre;
    int aumentoVida;
    int aumentoAtaque;
    int aumentoDefensa;
};

int opcionValida() {
    int opcion;
    while(true) {
        cout << "Opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un numero valido." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return opcion;
        }
    }
}

void ataqueAlEnemigo(Player& jugador, Enemigo& enemigo) {
    // Ataque del jugador al enemigo
    int damage = jugador.ataqueFisico - enemigo.defensa;
    if (damage < 0) {
        damage = 0;
    }

    enemigo.vida -= damage;

    cout << jugador.nombre << " le realiza un ataque a " << enemigo.nombre << " y el dano que realiza es " << damage << endl;

    if (enemigo.vida <= 0) {
        cout << enemigo.nombre << " fue destruido." << endl;
    }
    else {
        cout << enemigo.nombre << " tiene " << enemigo.vida << " puntos de vida restantes." << endl;
    }
}

void usarBooster(Player& jugador, Booster& booster) {
    // Como el jugador usa los booster
}

void ataqueAlJugador(Enemigo& enemigo, Player& jugador) {
    // Como el enemigo ataca al jugador

    // Enemigo derrotado que no puede atacar
    if (enemigo.vida <= 0) {
        cout << enemigo.nombre << " esta destruido y no puede atacar." << endl;
        return;
    }

    int damage = enemigo.ataque - jugador.defensa;
    if (damage < 0) {
        damage = 0;
    }

    jugador.vida -= damage;

    cout << " " << endl;
    cout << enemigo.nombre << " le realiza un ataque a " << jugador.nombre << " y el dano que realiza es " << damage << "\n" << endl;

    if (jugador.vida <= 0) {
        cout << jugador.nombre << " fue destruido." << "\n" << endl;
    }
    else {
        cout << jugador.nombre << " tiene " << jugador.vida << " puntos de vida restantes." << "\n" << endl;
    }
}

void verificarVidaJugador(Player& jugador) {
    if (jugador.vida <= 0) {
        cout << " " << endl;
        cout << " " << endl;
        cout << "GAME OVER! El jugador fue derrotado" << endl;
        cout << " " << endl;
        cout << " " << endl;
        exit(0);
    }
}


int main()
{
    Player jugador = { "Jugador", 100, 10, 15, 1, 0 };

    Enemigo enemigos[] = { {"Caza1", 50, 8, 3}, {"Caza2", 50, 8, 3}, {"Bombardero", 100, 3, 5} };

    Booster boosters[] = { "Reparacion", 15, 0, 0 };

    srand(time(0));

    // Funciones para la interaccion
    while (true) {

        cout << "Jugador: " << jugador.nombre << "\n" << " Vida: " << jugador.vida << "\n" << endl;
        cout << "Enemigos: \n" << endl;

        for (int i = 0; i < 3; i++) {
            if (enemigos[i].vida > 0) {
                cout << i + 1 << ". " << enemigos[i].nombre << " Vida: " << enemigos[i].vida << endl;
            }
            else {
                cout << i + 1 << ". " << enemigos[i].nombre << " Esta Derrotado." << endl;
            }
        }

            // Elegir al enemigo al cual atacar:
            int opcion;
            cout << " " << endl;
            cout << "A que enemigo quieres atacar (1, 2 o 3)?: ";

            opcion = opcionValida();

            // Ataque al enemigo
            if (opcion >= 1 && opcion <= 3) {
                ataqueAlEnemigo(jugador, enemigos[opcion - 1]);

                verificarVidaJugador(jugador);
            }
            else {
                cout << "Elegir un enemigo valido" << endl;
            }

            bool victoria = true;
            for (int i = 0; i < 3; i++) {
                if (enemigos[i].vida > 0) {
                    victoria = false;
                    break;
                }
            }
            if (victoria) {
                cout << " " << endl;
                cout << " " << endl;
                cout << "VICTORIA! Has derrotado a todos los enemigos" << endl;
                cout << " " << endl;
                cout << " " << endl;
                break;
            }

            system("cls");
            cout << jugador.nombre << " Le realiza un ataque a " << enemigos[opcion - 1].nombre << ". \n" << endl;

            // Codigo de como atacan los enemigos al jugador siendo que el enemigo que ataca se elije aleatoriamente:
            int enemigoAleatorio = rand() % 3; // Genera un número aleatorio entre 0 y 2
            cout << enemigos[enemigoAleatorio].nombre << " ataca al jugador." << endl;

            // Ataque al jugador
            ataqueAlJugador(enemigos[enemigoAleatorio], jugador);
    }

    cout << "Gracias por Jugar!" << endl;

        return 0;
    }

