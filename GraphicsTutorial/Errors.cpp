//
//  Errors.cpp
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/1/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#include "Errors.h"

void fatalError(const std::string& errorString) {
    printf("%s\n", errorString.c_str());
    printf("Enter any key to quit...");
    int a;
    a = getchar();
    SDL_Quit();
    exit(1);
}