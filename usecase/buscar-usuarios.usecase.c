#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers.h"

struct Buscar_usuarios_model buscar_usuarios_usecase() {
    return buscar_usuarios_repository();
}