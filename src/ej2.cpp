char * LeerCadena()
{
     char cadena[300];
     char *p;
     
     cin.getline(cadena, 300);

     p = new char [ strlen (cadena) + 1 ];
     
     strcpy( p, cadena );
     
     return p;
}

 