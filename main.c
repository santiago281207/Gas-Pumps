#define MIN_QTD_POSTOS 1
#define MAX_QTD_POSTOS 2000
#define DIST_DO_GASTO_EM_METROS 100000
#define DIST_GASTO_EM_KM 100
#include <stdio.h>


int EntreAB(int n,int min,int max);
int CustoEfetivo_por_Litro(int preco_por_litro,int qtd_abastecer,int dist_ate_bomba/*,int litros_por_100km*/);

int main()
{
    int menor_custo_efetivo = 0;
    int qtd_a_abastecer = 0,gasto_por_100km = 0;
    int qtd_postos = 0;
    int id_postos[MAX_QTD_POSTOS],dist_postos[MAX_QTD_POSTOS],preco_por_litro[MAX_QTD_POSTOS];
    int preco_efetivo[MAX_QTD_POSTOS];
    int i = 0;

    printf("Indique a quantidade a abastecer: ");
    scanf("%d",&qtd_a_abastecer);
    printf("Indique o gasto medio a cada 100 km: ");
    scanf("%d",&gasto_por_100km);

    do
    {
        printf("Indique a quantidade de postos: ");
        scanf("%d",&qtd_postos);
        if(EntreAB(qtd_postos,MIN_QTD_POSTOS,MAX_QTD_POSTOS) == 0)
        {
            puts("INVALIDO!");
        }
    } while (EntreAB(qtd_postos,MIN_QTD_POSTOS,MAX_QTD_POSTOS) == 0);

    for(i = 0;i < qtd_postos;i++)
    {
        id_postos[i] = i+1;
        printf("Distancia e preco do posto %d (D P): ",i+1);
        scanf("%d %d",&dist_postos[i],&preco_por_litro[i]);
        
        preco_efetivo[i] = CustoEfetivo_por_Litro(preco_por_litro[i],qtd_a_abastecer,dist_postos[i]/*,gasto_por_100km*/);

        if(i == 0)
        {
            menor_custo_efetivo = i;
        }
        else if(preco_efetivo[i] < preco_efetivo[menor_custo_efetivo])
        {
            menor_custo_efetivo = i;
        }
    }

    printf("Posto a usar: %d que esta a %d'm\n",id_postos[menor_custo_efetivo],dist_postos[menor_custo_efetivo]);
    return 0;
    
}

int EntreAB(int n,int min,int max)
{
    return n >= min && n <= max;
}

int CustoEfetivo_por_Litro(int preco_por_litro,int qtd_abastecer,int dist_ate_bomba/*,int litros_por_100km*/)
{
    int custo_total = qtd_abastecer * preco_por_litro;
    int km_a_percorrer = DIST_DO_GASTO_EM_METROS / dist_ate_bomba;
    int litros_gastos_ate_bomba = DIST_GASTO_EM_KM / km_a_percorrer ;
    int real_abastecido = qtd_abastecer - litros_gastos_ate_bomba;
    int valor_efetivo = custo_total / real_abastecido;

    return valor_efetivo;
}
