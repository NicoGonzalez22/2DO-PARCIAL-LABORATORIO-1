#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibrosFromText(FILE* pFile , LinkedList* listaLibros);

int parser_EditorialesFromText(FILE* pFile , LinkedList* listaEditoriales);
#endif /* PARSER_H_ */
