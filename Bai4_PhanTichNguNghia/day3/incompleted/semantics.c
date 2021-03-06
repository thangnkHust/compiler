/* 
 * @copyright (c) 2008, Hedspi, Hanoi University of Technology
 * @author Huu-Duc Nguyen
 * @version 1.0
 */

#include <stdlib.h>
#include <string.h>
#include "semantics.h"
#include "error.h"

extern SymTab* symtab;
extern Token* currentToken;

// Find Object by name in all block of symbal
Object* lookupObject(char *name) {
	Scope *scope = symtab->currentScope;
	Object *obj;

	// Search in symbol table
	while(scope != NULL){
		obj = findObject(scope->objList, name);
		if(obj != NULL)
			return obj;
		scope = scope->outer;
	}
	// Search in global object
	obj = findObject(symtab->globalObjectList, name);
	if(obj != NULL)
		return obj;
	return NULL;
}

// Fresh in a block
void checkFreshIdent(char *name) {
	Object *obj = findObject(symtab->currentScope->objList, name);
	if(obj != NULL)
		error(ERR_DUPLICATE_IDENT, currentToken->lineNo, currentToken->colNo);
}

// Check ident has been declareed ?
Object* checkDeclaredIdent(char* name) {
	Object *obj = lookupObject(name);
	if(obj == NULL)
		error(ERR_UNDECLARED_IDENT, currentToken->lineNo, currentToken->colNo);
	return obj;
}

// Check constant has been declared ?
Object* checkDeclaredConstant(char* name) {
	Object *obj = NULL;
	do{
		obj = lookupObject(name);
		if(obj != NULL && obj->kind == OBJ_CONSTANT)
			break;
	}while(obj != NULL);
	if(obj == NULL) 
		error(ERR_UNDECLARED_CONSTANT, currentToken->lineNo, currentToken->colNo);

	return obj;
}

Object* checkDeclaredType(char* name) {
	Object *obj = NULL;
	do{
		obj = lookupObject(name);
		if(obj != NULL && obj->kind == OBJ_TYPE)
			break;
	}while(obj != NULL);
	if(obj == NULL) 
		error(ERR_UNDECLARED_TYPE, currentToken->lineNo, currentToken->colNo);

	return obj;
}

Object* checkDeclaredVariable(char* name) {
	Object *obj = NULL;
	do{
		obj = lookupObject(name);
		if(obj != NULL && obj->kind == OBJ_VARIABLE)
			break;
	}while(obj != NULL);
	if(obj == NULL) 
		error(ERR_UNDECLARED_VARIABLE, currentToken->lineNo, currentToken->colNo);

	return obj;
}

Object* checkDeclaredFunction(char* name) {
	Object *obj = NULL;
	do{
		obj = lookupObject(name);
		if(obj != NULL && obj->kind == OBJ_FUNCTION)
			break;
	}while(obj != NULL);
	if(obj == NULL) 
		error(ERR_UNDECLARED_FUNCTION, currentToken->lineNo, currentToken->colNo);

	return obj;
}

Object* checkDeclaredProcedure(char* name) {
	Object *obj = NULL;
	do{
		obj = lookupObject(name);
		if(obj != NULL && obj->kind == OBJ_PROCEDURE)
			break;
	}while(obj != NULL);
	if(obj == NULL) 
		error(ERR_UNDECLARED_PROCEDURE, currentToken->lineNo, currentToken->colNo);

	return obj;
}

// Check declare value has been declared ?
Object* checkDeclaredLValueIdent(char* name) {
	Object *obj = NULL;
	do{
		obj = lookupObject(name);
		if(obj != NULL && (obj->kind == OBJ_FUNCTION || obj->kind == OBJ_PARAMETER || obj->kind == OBJ_VARIABLE))
			break;
	}while(obj != NULL);
	if(obj == NULL) 
		error(ERR_UNDECLARED_IDENT, currentToken->lineNo, currentToken->colNo);

	return obj;
}

