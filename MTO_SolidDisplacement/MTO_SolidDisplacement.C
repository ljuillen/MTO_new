//Author: Yu Minghao    Updated: May 2020     Email:yuminghao_dlut@163.com

static char help[] = "topology optimization of linear elasticity problem\n";
#include "fvCFD.H"
#include "simpleControl.H"
#include <MMA.h>
#include <diff.c>
int main(int argc, char *argv[])
{
    PetscInitialize(&argc,&argv,PETSC_NULL,help);
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createControl.H"
    #include "createFields.H"
    #include "readMechanicalProperties.H" 
    #include "opt_initialization.H"
    while (simple.loop())
    {
        #include "update.H"
        #include "LinearElasticity.H"
        #include "costfunction.H"              
        #include "sensitivity.H"
    }
    #include "finalize.H"
    return 0;
}
