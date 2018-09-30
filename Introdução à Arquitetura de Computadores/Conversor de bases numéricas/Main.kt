import java.util.*

fun main(args: Array<String>) {

    var running = true
    val input = Scanner(System.`in`)
    while (running){
        print("Digite a opção de desejada" +
                "\n1 - Binário para Decimal" +
                "\n2 - Decimal para Binário" +
                "\n3 - Decimal para Hexadecimal" +
                "\n4 - Hexadecimal para Decimal" +
                "\n qualquer outra tecla para sair: ")
        var option = input.nextLine()
        var result = ""
        if (option.isNotBlank())
            when(option){
                "1"->{
                    print("Digite o número para converter: ")
                    result = binToDec(input.nextLine())

                }
                "2"->{
                    print("Digite o número para converter: ")
                    result = decToBin(input.nextLine())
                }
                "3"->{
                    print("Digite o número para converter: ")
                    result = decToHexa(input.nextLine())
                }
                "4"->{
                    print("Digite o número para converter: ")
                    result = hexaToDec(input.nextLine())
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
fun binToDec(n:String): String{
    var decimal = 0

    try {
        for (i in  n){
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
fun decToBin(n: String): String{
    var binario = ""
    var decimal = 0
    try {
        decimal = n.toInt()
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
fun hexaToDec(n:String): String {
    var decimal = 0

    for (i in n){
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

fun decToHexa(n:String): String{
    var hexa = ""
    var decimal = 0
    for (i in n){
        if (i.toInt() !in 48..57){ //VALOR ASCII do intervalo numérico 0 a 9
            println("Valor de Entrada inválido")
            return ""
        }}
        decimal = n.toInt()

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
