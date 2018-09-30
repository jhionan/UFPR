/***
 * Circuito Somado
 * Operações Lógicas
 * Conversor de bases
 * */

fun main(args: Array<String>) {

    var running = true
    while (running){
        running =  mainMenu()
    }

}



fun mainMenu(): Boolean{
    print("Digite A opção desejada:" +
            "\n1: Módulo de operadores lógicos" +
            "\n2: Módulo de conversores de base" +
            "\n3: Calculadora binária" +
            "\n qualquer outra coisa para sair: ")



    when(readLine()) {
        "1" -> numberConversor()
        "2" -> logicOperations()
        "3" -> binaryCalculator()
        else -> return false

    }

    return true
}




fun numberConversor() {

    var running = true
    while (running){
        print("Digite a opção de desejada" +
                "\n1 - Binário para Decimal" +
                "\n2 - Decimal para Binário" +
                "\n3 - Decimal para Hexadecimal" +
                "\n4 - Hexadecimal para Decimal" +
                "\n qualquer outra tecla para sair: ")
        var option = readLine()
        var result  = ""
        if (option?.isNotBlank() == true)
            when(option){
                "1"->{
                    print("Digite o número para converter: ")
                    result = binToDec(readLine())

                }
                "2"->{
                    print("Digite o número para converter: ")
                    result = decToBin(readLine())
                }
                "3"->{
                    print("Digite o número para converter: ")
                    result = decToHexa(readLine())
                }
                "4"->{
                    print("Digite o número para converter: ")
                    result = hexaToDec(readLine())
                }
                else ->running = false
            }
        if (running&&result.isNotBlank())
            println("==================================\nO Resultado é: $result\n==================================")
    }
}

/** Curiosidade sobre Kotlin
 * Como o paradigma é Orientado a Objeto / Funcional, não é nescessário ter classes para chamar funcões..
 * */

const val A = 10
const val B = 11
const val C = 12
const val D = 13
const val E = 14
const val F = 15
const val CHAR_ASCII = 87
const val ZERO_ASCII = '0'.toInt() //quando chama toInt() do kotlin em um char ele trás o valor ascc no caso 0 = 48
/***
 * Somo o valor do 1º algarismo a esquerda e multiplico por 2
 * depois somo ao 2º algarismo e multiplico por 2
 * quando chegar no ultimo não devo multiplicar por 2, apenas somar
 * como esta dentro do laço for, apos o laço eu divido por 2 pra compensar uma multiplicaçao a mais que o laço faz
 * */
fun binToDec(n:String?): String{
    var decimal = 0

    try {
        for (i in  n?:""){
            if ((i.toInt()-ZERO_ASCII)>1){
                println("Número de entrada não é um binário!!!")
                return ""
            }
            decimal += (i.toInt()-ZERO_ASCII)
            decimal*=2
        }
        decimal/=2
    }catch (e: Throwable){
        println("Input incorreto, não é possível operar!" +
                "\n retornando 0")
    }
    return decimal.toString()
}

/**
 * pega o resto da divisao por 2 e por numa string
 * divide por 2 (é inteiro nao tem resto)
 * se for menor que 2 ai adiciona a string
 * inverte a string e transforma em numero
 * */
fun decToBin(n: String?): String{
    var binario = ""
    var decimal: Int
    try {
        decimal = n?.toInt()?:0
        while (decimal>1){
            binario += ""+decimal%2

            decimal /= 2
        }
        if (decimal<2)
            binario +=decimal
    } catch (e:Throwable){
        println("Input incorreto, não é possível operar!")
        return ""
    }
    binario = binario.reversed()
    return binario
}


/**
 * Mesma lógica do binário + tratando quando for letra
 * */
fun hexaToDec(n:String?): String {
    var decimal = 0

    for (i in n?:""){
        //102 = F   //  58 a 96 é o range da diferença entre o valor ascii dos numeros e das letras iniciais
        if (i.toInt()>102||i.toInt()<ZERO_ASCII||(i.toInt() in 58..96)){
            println("Valor de Entrada não é um Hexadecimal")
            return ""
        }

        if (i.toInt()<97)
            decimal += i.toInt()-ZERO_ASCII
        else
            decimal += i.toInt()-CHAR_ASCII
        decimal *=16

        println("$decimal ${i.toInt()}")
    }
    decimal /=16

    return decimal.toString()
}

fun decToHexa(n:String?): String{
    var hexa = ""
    var decimal = n?.toInt()?:0
    for (i in n?:""){
        if (i.toInt() !in 48..57){ //VALOR ASCII do intervalo numérico 0 a 9
            println("Valor de Entrada inválido")
            return ""
        }}

    while (decimal>15) {

        hexa += when(decimal % 16){
            A-> "A"
            B-> "B"
            C-> "C"
            D-> "D"
            E-> "E"
            F-> "F"
            else-> decimal % 16
        }
        decimal /= 16
        print(decimal % 16)
    }
    if (decimal<16)
        hexa += when(decimal % 16) {
            A -> "A"
            B -> "B"
            C -> "C"
            D -> "D"
            E -> "E"
            F -> "F"
            else -> decimal
        }
    println("hexa: $hexa e resto ${decimal % 16}")


    return hexa.reversed()
}


fun logicOperations() {



    var running = true
    while (running) {

        print("Digite uma opção para escolher a função desejada" +
                "\n1 - Função E" +
                "\n2 - FUnção OU" +
                "\n3 - Função XOR" +
                "\n4 - Função NÃO" +
                "\n5 - Função NÃOE" +
                "\n6 - Função NÃOOU" +
                "\n Qualquer outra coisa para encerrar: ")

        val optionIn = readLine()

        var option = 0
        if (optionIn?.isNotBlank()==true)
            try {
                option = optionIn.toInt()
                if (option > 9 || option < 0)
                    running = false
            } catch (e: Throwable) {
                running = false
            }


        var result = false
        when (option) {

            1 -> {
                print("Digite o 1 bit: ")
                var b1 = readLine()
                print("Digite o 2 bit: ")
                var b2 = readLine()
                result = and(b1, b2)
            }
            2 -> {
                print("Digite o 1 bit: ")
                var b1 = readLine()
                print("Digite o 2 bit: ")
                var b2 = readLine()
                result = or(b1, b2)
            }
            3->{
                print("Digite o 1 bit: ")
                var b1 = readLine()
                print("Digite o 2 bit: ")
                var b2 = readLine()
                result = xor(b1, b2)
            }
            4->{
                print("Digite o 1 bit: ")
                var b1 = readLine()
                result = not(b1)
            }
            5->{
                print("Digite o 1 bit: ")
                var b1 = readLine()
                print("Digite o 2 bit: ")
                var b2 = readLine()
                result = nand(b1, b2)
            }
            6->{
                print("Digite o 1 bit: ")
                var b1 = readLine()
                print("Digite o 2 bit: ")
                var b2 = readLine()
                result = nor(b1, b2)
            }
            else-> running = false

        }
        if (running)
            print("================\nResultado: $result\n================")
        println()
        if (running)
            readLine()
    }

}

/***FUnçoes*/
fun and(bit1: String?, bit2: String?) : Boolean{

    return if (bit1=="1"){
        bit2=="1"
    }else
        false
}


fun or(bit1:String?, bit2: String?) = if (bit1=="1") true else bit2=="1"


fun not(b1:String?) = if (b1=="1") false else true
fun notInt(b1:String?) = if (b1=="1") "0" else "1"
fun not(b1: Boolean) = !b1


fun xor(b1: String?, b2: String?) = and(b1, notInt(b2))

fun nand(b1: String?,b2: String?) = not(and(b1,b2))

fun nor(b1:String?, b2: String?) = not(or(b1,b2))



/*** SOmador */


fun binaryCalculator() {
    val somaAula = listOf<Soma>(Soma(decToBin("4").toInt(),decToBin("4").toInt()),
            Soma(decToBin("5").toInt(),decToBin("1").toInt()),
            Soma(decToBin("6").toInt(),decToBin("7").toInt()),
            Soma(decToBin("7").toInt(),decToBin("0").toInt()),
            Soma(decToBin("0").toInt(),decToBin("0").toInt()),
            Soma(decToBin("1").toInt(),decToBin("1").toInt()),
            Soma(decToBin("2").toInt(),decToBin("3").toInt()),
            Soma(decToBin("3").toInt(),decToBin("0").toInt()),
            Soma(decToBin("12").toInt(),decToBin("12").toInt()),
            Soma(decToBin("13").toInt(),decToBin("1").toInt()),
            Soma(decToBin("14").toInt(),decToBin("15").toInt()),
            Soma(decToBin("15").toInt(),decToBin("0").toInt()),
            Soma(decToBin("8").toInt(),decToBin("8").toInt()),
            Soma(decToBin("9").toInt(),decToBin("1").toInt()),
            Soma(decToBin("10").toInt(),decToBin("11").toInt()),
            Soma(decToBin("11").toInt(),decToBin("0").toInt()))
    var running = true
    while (running){

        print("Digite a opção desejada:" +
                "\n1 - Rodar soma estipulada na aula" +
                "\n2 - Digitar números para somar" +
                "\n Qualquer outra coisa para sair")

        when(readLine()){
            "1"-> somaBinaria(somaAula)
            "2" -> somaBinaria()
            else -> running = false
        }


    }

}


fun somaBinaria(somaAula: List<Soma>? = null) {

    if (somaAula!=null){

    }else{

    }
}

data class Soma(val numero1: Int, val numero2: Int)