

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int menu(int* kilometros,float* preAerolineas, float* preLatam);
int precioVuelos(float* aerolineas,float* latam);
int calcularTodosLosCostos(int kilometros,float pAerolineas, float pLatam,float* tarjetaLatam,float* creditoLatam, float* btcLatam, float* unitarioLatam,float* tarjetaAerolineas,float* creditoAerolineas,float* btcAerolineas,float* unitarioAerolineas,float* diferencia);
void informarResultado(float tarjetaLatam,float creditoLatam,float btcLatam,float unitarioLatam,float tarjetaAerolineas,float creditoAerolineas,float btcAerolineas,float unitarioAerolineas,float diferencia);
void cargaForzada();
#endif /* FUNCIONES_H_ */
