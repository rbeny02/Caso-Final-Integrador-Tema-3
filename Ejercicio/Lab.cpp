//
// Created by rania on 25/11/2024.
//
#include "Ejercicio/Lab.h"
#include <iostream>
#include <cstdio>

using namespace std;


const char* ColorConsole::fg_blue = "\033[34m";
const char* ColorConsole::bg_white = "\033[47m";


ConsoleBox* consoleBox = nullptr;


void ConsoleBox::new_text() {

    cout << "Nuevo texto cargado." << endl;
}


void ConsoleBox::set_text(const string &text) {

    cout << "Texto recibido: " << text << endl;
}


void load_script(const char* filename, bool show_script) {

    if (!consoleBox) {
        consoleBox = new ConsoleBox();
    }

    string script;
    FILE* f = fopen(filename, "rb");
    if (!f) {
        cerr << "Error al abrir " << filename << endl;
        return;
    }

    try {
        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0) {
            buf[c] = 0;
            script.append(buf);
        }

        if (show_script) {

            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }


        consoleBox->new_text();
        consoleBox->set_text(script);

    } catch (...) {
        cerr << "Error leyendo el archivo." << endl;
    }

    if (f) fclose(f);
}


void load_script() {
    char filename[500];
    printf("Archivo: ");
    scanf("%499s", filename);
    load_script(filename, true);
}
