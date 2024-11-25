//
// Created by rania on 25/11/2024.
//
#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct ColorConsole
{
    static const char* fg_blue;
    static const char* bg_white;
};

struct ConsoleBox
{
    void new_text();
    void set_text(const string &text);
};

extern ConsoleBox* consoleBox;


void load_script(const char* filename, bool show_script = false);
void load_script();  /

#endif // LAB_H
