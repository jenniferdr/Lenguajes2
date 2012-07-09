// Metodos gen de los Quads 
#include <list>

#include "Quad.hh"
#include "MIPSinstruction.hh"



/** 
 * Asignacion de 3 o 2 direcciones
 * x:= y op z  =>  Rd:= Rx op Ry  
 * x:= op y    =>  Rd:= op Rx
 **//*
std::list<MIPSinstruction*> AsignmentOpQ::gen(){
  // Ver que registros convienen "getReg" para x, y 
  // Si arg2 no en null ver que registro le conviene

  // Si y(no es una constant) y no pertenece a Assig(Ry) 
    // Buscar el y mas econom en Av(y)
    // lista.add(new Lw(Ry,y)) 
  // Si es una constante lista.add(new Li(Ry,y))

  // Lo mismo para z en caso de no ser null
  // Pero si usaremos addi y es const no hace falta colocarla en reg 
  // lista.add(new Ld(Rz,z))
  /*
  // Dependiendo del operador se gen la instruccion  
  switch(this.op){
  case Operator::sumI:
    // Si el segundo es una constante usar Addi
    //lista.add(new Add(Rx,Ry,Rz));
  case Operator::sumF:
    
  case Operator::substractionI:
    
  case Operator::substractionF:
    
  case Operator::multiplicationI:
    
  case Operator::multiplicationF:
    
  case Operator::divisionI:
  case Operator::divisionF:
  case Operator::remainder:
  case Operator::minusI:
  case Operator::minusF:
  }
}
*/

std::list<Instruction*> JumpQ::gen() {
  std::list<Instruction*> res;
  res.push_back(new J(this->label));
  return res;
}

std::list<Instruction*> CallQ::gen() {
  std::list<Instruction*> res;
  res.push_back(new Jal(func->getLabel()));
  return res;
}
