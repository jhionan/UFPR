Program Trabalho2;
USES Trabalho2Unit;
var dd,mm,yy:Integer;
begin
     
     dd:=-1;
     mm:=0;
     yy:=0;


Repeat
 Repeat
 Write('dia ou  0 para encerra ->');
 Readln(dd);
 if not(dd=0) then
 begin

 Write('mes->');
 Readln(mm);
 Write('ano->');
 Readln(yy); 
 
 End;
 


Until((dd=0) OR (VALIDATA(dd,mm,yy))); //chama function
if VALIDATA(dd,mm,yy) then
 EXTENSO(dd,mm,yy)
 
 Until(dd=0);

End.
