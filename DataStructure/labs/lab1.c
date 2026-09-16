#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode{
    float coef;
    int exp;
    struct PolyNode* next;
}PolyNode,*Polynomial;

void CreatePolynomial(Polynomial Plnm,char *buf,int* idx){
    if(!buf)
        return;

    PolyNode *p,*tail;
    Plnm->next = NULL;

    if(buf[*idx] == '(')
        (*idx)++;

    while(buf[*idx] != ')'){
        char c = buf[*idx];
        if(c == '0' && buf[(*idx)+1] != '.')
            return;

        p = (PolyNode*)malloc(sizeof(PolyNode));

        if(c == '+' || c == '-' || c > '0' && c <= '9'){
            float coef;
            if(buf[(*idx)+1] == 'x' && !(c > '0' && c <= '9')){
                p->coef = c == '+' ? 1 : -1;
                (*idx)++;
            }
            else{
                sscanf(&buf[*idx],"%f",&coef);//sscanf(buf,"%d",&p->coef);
                p->coef = coef;
                do
                    (*idx)++;
                while(buf[*idx] >= '0' && buf[*idx] <= '9' || buf[*idx] == '.');
            }
        }
        else if(c == 'x')
            p->coef = 1;


        if(buf[*idx] == 'x'){
            if(buf[*idx+1] != '^'){
                p->exp = 1;
                (*idx)++;
            }
            else{
                int exp;
                (*idx) += 2;
                sscanf(&buf[*idx],"%d",&exp);
                p->exp = exp;
                do
                    (*idx)++;
                while(buf[*idx] >= '0' && buf[*idx] <= '9');
            }
        }
        else
            p->exp = 0;

        p->next = NULL;

        if(!Plnm->next)
            Plnm->next = p;
        else
            tail->next = p;

        tail = p;
    }

    return;
}

void PrintPolynomial(Polynomial pl){
    PolyNode *p = pl->next;

    if(!p){
        printf("0\n");
        return;
    }

    if(!p->exp){
        printf("%.2f",p->coef);
    }
    else{
        if(p->coef == 1 || p->coef == -1){
            if(p->coef == -1)
                printf("-x");
            else
                printf("x");
        }
        else
            printf("%.2fx",p->coef);
        
        if(p->exp > 1)
            printf("^%d",p->exp);
    }

    p = p->next;
    while(p){
        if(!p->exp){
            if(p->coef > 0)
                printf("+");

            printf("%.2f",p->coef);
        }
        else{
            if(p->coef == 1 || p->coef == -1){
                if(p->coef == -1)
                    printf("-x");
                else
                    printf("+x");
            }
            else{
                if(p->coef > 0)
                    printf("+%.2fx",p->coef);
                else
                    printf("%.2fx",p->coef);
            }
        
            if(p->exp != 1)
                printf("^%d",p->exp);
        }

        p = p->next;
    }

    printf("\n");
    return;
    
}

void PrintCE(Polynomial PLNM){
    PolyNode *p = PLNM->next;
    while(p){
        printf("(%.2f,%d)\n",p->coef,p->exp);
        p = p->next;
    }
        
}

Polynomial SortPoly(Polynomial PLNM){
    if((!PLNM) || (!PLNM->next))
        return PLNM;

    Polynomial SortedP = (PolyNode*)malloc(sizeof(PolyNode));
    PolyNode *p = PLNM->next;
    PolyNode *next = p->next;
    p->next = NULL;
    SortedP->next = p;
    p = next;
    
    while(p){
        PolyNode *q = SortedP->next,*pre = SortedP;
        int tmp = p->exp;

        while(q && q->exp > tmp){
            pre = q;
            q = q->next;
        }
        
        next = p->next;
        if(!q){
            p->next = NULL;
            pre->next = p;
            p = next;
        }
        else if(q->exp == tmp){
            q->coef += p->coef;
            p = next;
        }
        else{
            p->next = q;
            pre->next = p;
            p = next;
        }
    }

    return SortedP;
}

Polynomial CalPoly(Polynomial P1,Polynomial P2,int op){
    if(!P1->next)
        return P2;
    
    if(!P2->next)
        return P1;

    Polynomial SumPoly = (PolyNode*)malloc(sizeof(PolyNode));
    PolyNode *p = P1->next,*q = P2->next,*node,*tail;
    SumPoly->next = NULL;

    while(p && q){
        node = (PolyNode*)malloc(sizeof(PolyNode));

        if(p->exp > q->exp){
            node->coef = p->coef;
            node->exp = p->exp;
            node->next = NULL;
            p = p->next;
        }
        else if(p->exp < q->exp){
            node->coef = op * q->coef;
            node->exp = q->exp;
            node->next = NULL;
            q = q->next;
        }
        else{
            node->coef = p->coef + op * q->coef;
            if(!node->coef){
                free(node);
                p = p->next;
                q = q->next;
                continue;
            }
            else{
                node->exp = p->exp;
                node->next = NULL;
                p = p->next;
                q = q->next;
            }
        }

        if(!SumPoly->next)
            SumPoly->next = node;
        else
            tail->next = node;
        tail = node;
    }

    if(p)
        tail->next = p;
    else if(q)
        tail->next = q;

    return SumPoly;

}

int Coef_of_x(Polynomial PLNM){
    if((!PLNM) || (!PLNM->next))
        return 0;
    
    PolyNode *p = PLNM->next;
    while(p){
        if(p->exp == 1)
            break;
        
        p = p->next;
    }

    if(p)
        return (int)p->coef;
    else
        return 0;
}

Polynomial Deriv(Polynomial PLNM){
    if((!PLNM) || (!PLNM->next))
        return PLNM;

    Polynomial der = (PolyNode*)malloc(sizeof(PolyNode));
    der->next = NULL;
    PolyNode *p = PLNM->next,*tail;
    while(p){

        if(!p->exp){
            p = p->next;
            continue;;
        }

        PolyNode *node = (PolyNode*)malloc(sizeof(PolyNode));
        node->coef = p->coef * p->exp;
        node->exp = p->exp - 1;
        node->next = NULL;

        if(!der->next)
            der->next = node;
        else
            tail->next = node;
        tail = node;

        p = p->next;
    }

    return der;
}

int main(){
    char buf[1024];
    fgets(buf, 1024, stdin);

    Polynomial PLNM1 = (PolyNode*)malloc(sizeof(PolyNode));
    Polynomial PLNM2 = (PolyNode*)malloc(sizeof(PolyNode));
    int idx = 0;
    CreatePolynomial(PLNM1,buf,&idx);
    //PrintCE(PLNM1);
    //PrintPolynomial(PLNM1);

    int op = buf[++idx] == '+' ? 1 : -1;

    idx++;
    CreatePolynomial(PLNM2,buf,&idx);
    //PrintCE(PLNM2);
    //PrintPolynomial(PLNM2);

    PLNM1 = SortPoly(PLNM1);
    PLNM2 = SortPoly(PLNM2);
    //PrintPolynomial(PLNM1);
    //PrintPolynomial(PLNM2);

    Polynomial SUM = CalPoly(PLNM1,PLNM2,op);

    printf("= ");
    //PrintCE(SUM);
    PrintPolynomial(SUM);
    printf("多项式在x处的值(一次项系数):%d\n",Coef_of_x(SUM));
    
    Polynomial deriv = Deriv(SUM);
    printf("SUM的导数:");
    PrintPolynomial(deriv);


    return 0;
}

