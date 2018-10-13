

Program L2Eextra1 ;
 const mes:array[1..12] of string[12] = ('janeiro','fevereiro','marco','abril','maio',
          'junho','julho','agosto','setembro','outubro','novembro','dezembro');
 var dd,mm,aa:integer;
Begin
  write('digite o dia->');
  readln(dd);
  while dd > 0 do
   begin
	  write('digite o mes->');
    readln(mm);
    write('digite o ano->');
    readln(aa);

    write(dd:2,' de ',mes[mm],' de ',aa);
    writeln;
    writeln;
    write('digite o dia->');
    readln(dd);
   end;
   write('enter para encerrar');
   readln;
End.