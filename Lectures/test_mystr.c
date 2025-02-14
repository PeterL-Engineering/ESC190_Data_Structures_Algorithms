#include "mystr.h"
#include <stdio.h>
#include <string.h>

void destroy_string(mystr* p_s){
    free(p_s.block); // free the block first
    free(p_s); // then free p_s
}

int main(){
    mystr* p_s;
    create_string(&p_s); // p_s is now a valid pointer to
                         // an empty string
    
    append_str(p_s, "hi");
    printf("The string: %s\n", p_s->block); // hi

    append_str(p_s, "hello");
    printf("The string: %s\n", p_s->block); // hihello

    destroy_string(p_s);
    return 0;
}