#include "../../includes/utils/simbolos.hpp"

int Simbolo::is_proc() {
    return (this->tipo_simbo == process) || (this->tipo_simbo == function);
}