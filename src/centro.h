#ifndef MENU_H
#define MENU_H
using namespace std;
// #include <string>

typedef struct
    {
        string codigo;
        string nombre;
        string pais;
        float superficie;
        int cant_laboratorios;
        int cant_p_nacionales;
        int cant_p_internacionales;
    } Centro;

struct CentroEliminado : public Centro {
    CentroEliminado instance = nullptr;

    private:
        CentroEliminado();

    public:
        CentroEliminado getInstance() {
            if(CentroEliminado.instance == nullptr) {
                CentroEliminado.instance = new CentroEliminado();
            }
        };
}

#endif //MENU_H