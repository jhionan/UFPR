program cpfValidator;

//professor não tenho windows em casa pra utilizar o pasqualzin  (só mac)
//fiz o programa pelo site: https://www.jdoodle.com/execute-pascal-online#

uses sysutils;
var cpf:String;
    i,n:Integer;
    valid : Boolean;
   
    
    
    function Validate(cpf:String; digito,posicao:Integer):Boolean;
        begin
       
            if(posicao=1) then
            begin
          
                if(StrToint(cpf[10])=digito) then
                Validate:=true
                else
                Validate:=false;
            end
            else
                if(posicao=2) then
                begin
               
                     if(StrToint(cpf[11])=digito) then
                    Validate:=true
                    else
                    Validate:=false;
                end
                else
                Validate:=false;
        end;
    

    function ValidatorDigit(multiply: Integer):Integer;
        var validator:Integer;
        begin
         validator:=0;
        
    for i:=1 to multiply-1 do
        begin
            validator:=validator+StrToint(cpf[i])*multiply;
          
             multiply:=multiply-1;
       
            end; //for
           
            validator:=validator*10;
            ValidatorDigit:=validator MOD 11;
           
        end;

 

begin //program
valid := false;
cpf:='22';

    while (NOT((Length(cpf)=1) AND ((cpf[1]='0')))) do
  begin
  writeln('Digite um cpf ou digite 0 para sair:');
    readln(cpf);
    
  
    
    for i:=1 to Length(cpf) do
        begin
        if(cpf[i]='.') then
            delete(cpf,i,1);
        if(cpf[i]='-') then
            delete(cpf,i,1);
    end; //for
    cpf:=Trim(cpf);
    
    
  if(NOT((cpf[1]=cpf[2]) AND (cpf[1]=cpf[3]) AND (cpf[1]=cpf[4]) AND (cpf[1]=cpf[5]) AND (cpf[1]=cpf[6]) AND (cpf[1]=cpf[7]) AND (cpf[1]=cpf[8]) AND (cpf[1]=cpf[9]) AND (cpf[1]=cpf[10]) AND (cpf[1]=cpf[11])) AND (Length(cpf)=11)) then
    for n:=1 to 2 do
        begin
        writeln('entrou aqui');
        valid:= Validate(cpf,ValidatorDigit(9+n),n);
         if(NOT(valid)) then
            Break;
        end; //for
        
     if(valid) then
        writeln('CPF ', cpf,' VALIDO')
        else
        writeln('CPF ', cpf,' INVALIDO');
    valid:=false;
   
 end;
  writeln('Enter Para encerrar');
  readln();
end.
