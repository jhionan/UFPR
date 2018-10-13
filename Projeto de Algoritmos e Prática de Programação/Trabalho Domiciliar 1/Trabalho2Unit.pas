UNIT Trabalho2Unit ;

//--------------------------------------------------------------------------
INTERFACE //serve para criar as vari�veis globais e indicar os m�dulos que faze parte da UNIT

//DECLAFRACAO DE VARIAVEIS GLOBAIS

VAR P1,P2,N:INTEGER;  

//MODULOS DA BIBLIOTECA COM PARAMETROS

 FUNCTION VALIDATA(DIA,MES,ANO:INTEGER):BOOLEAN;
 FUNCTION INTEIRO(NN:REAL):INTEGER;
 FUNCTION RESTO(A,B:INTEGER):INTEGER;
 PROCEDURE TESTA(RES:INTEGER; VAR MU,NMU:INTEGER);
 PROCEDURE SAI;
 PROCEDURE EXTENSO(dd,mm,aa : INTEGER);

IMPLEMENTATION

//MODULOS FISICOS

FUNCTION INTEIRO(NN:REAL):INTEGER;
VAR DIV1 :REAL;
    INTEE,MULT:INTEGER;
       BEGIN        
          DIV1 := NN ;
          MULT := 1;
          IF (DIV1 < 0) THEN
               MULT :=  -1;
          DIV1 := DIV1 * MULT;
          INTEE := 0;
          REPEAT
              INTEE := INTEE+1;
          UNTIL (INTEE > DIV1);
          INTEIRO:=(INTEE - 1) * MULT;
			 END;
//---------------------------------------------------------------------------
FUNCTION RESTO(A,B:INTEGER):INTEGER;
VAR INTEE:INTEGER;
       BEGIN
          INTEE := INTEIRO(A/B);
          RESTO := A-INTEE * B;
      END;
//---------------------------------------------------------------------------
PROCEDURE SAI;
    BEGIN
      WRITELN('MULTIPLOS DE ',N:10,' =', P1:10 );
      WRITELN('N�O MULTIPLOS DE ' ,N:10, ' =', P2:10);
   END;
//--------------------------------------------------------------------------
 PROCEDURE TESTA(RES:INTEGER; VAR MU,NMU:INTEGER);
       BEGIN
          IF  (RES = 0) THEN
               MU := MU + 1
          ELSE
              NMU := NMU + 1;
       END;
//---------------------------------------------------------------------------
FUNCTION VALIDATA(DIA,MES,ANO:INTEGER):BOOLEAN;
VAR DIAMAX:INTEGER;
    CHAVE:BOOLEAN;
BEGIN
 CHAVE:=TRUE;
 IF(ANO < 1900)THEN //VERIFICA O ANO
  CHAVE:=FALSE
 ELSE
  IF(MES < 1) OR (MES > 12)THEN //VERIFICA O MES
   CHAVE:=FALSE
  ELSE
   BEGIN //INICIO DA VERIFICACAO DO DIA
    DIAMAX:=31;  //PARA TODOS OS MESES
    IF(MES=4) OR (MES=6) OR (MES=9) OR (MES=11) THEN  //ALTERA 
     DIAMAX:=30;
    IF(MES=2)THEN // ALTERA
     BEGIN
      DIAMAX:=28;
      IF(ANO MOD 4 = 0)THEN //ALTERA
       DIAMAX:=29;
     END;
     IF(DIA < 1) OR (DIA > DIAMAX) THEN
      CHAVE:= FALSE;
    END;
 VALIDATA:=CHAVE;
END;

PROCEDURE EXTENSO(dd, mm,aa : INTEGER);
 const mes:array[1..12] of string[12] = ('janeiro','fevereiro','marco','abril','maio',
          'junho','julho','agosto','setembro','outubro','novembro','dezembro');
BEGIN
   
    write(dd:2,' de ',mes[mm],' de ',aa);
    writeln;
    writeln;
END;



END.