import java.util.Scanner;
/**
 * Feito por Jhionan Rian Lara dos Santos - GRR20184624
 * Trabalho para DS011 Introdução à Arquitetura de Computadores - N
 *
 * */

fun main(args: Array<String>) {



    val value = Scanner(System.`in`)
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

        val optionIn = value.nextLine()

        var option = 0
        if (optionIn.isNotBlank())
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
                var b1 = value.nextInt()
                print("Digite o 2 bit: ")
                var b2 = value.nextInt()
                result = and(b1, b2)
            }
            2 -> {
                print("Digite o 1 bit: ")
                var b1 = value.nextInt()
                print("Digite o 2 bit: ")
                var b2 = value.nextInt()
                result = or(b1, b2)
            }
            3->{
                print("Digite o 1 bit: ")
                var b1 = value.nextInt()
                print("Digite o 2 bit: ")
                var b2 = value.nextInt()
                result = xor(b1, b2)
            }
            4->{
                print("Digite o 1 bit: ")
                var b1 = value.nextInt()
                result = not(b1)
            }
            5->{
                print("Digite o 1 bit: ")
                var b1 = value.nextInt()
                print("Digite o 2 bit: ")
                var b2 = value.nextInt()
                result = nand(b1, b2)
            }
            6->{
                print("Digite o 1 bit: ")
                var b1 = value.nextInt()
                print("Digite o 2 bit: ")
                var b2 = value.nextInt()
                result = nor(b1, b2)
            }
            else-> running = false

        }
        if (running)
        print("================\nResultado: $result\n================")
        println()
        if (running)
        value.nextLine()
    }

}

/***FUnçoes*/
fun and(bit1: Int, bit2: Int) : Boolean{

    return if (bit1==1){
        bit2==1
    }else
        false
}


fun or(bit1:Int, bit2: Int) = if (bit1==1) true else bit2==1


fun not(b1:Int) = if (b1==1) false else true
fun notInt(b1:Int) = if (b1==1) 0 else 1
fun not(b1: Boolean) = !b1


fun xor(b1: Int, b2: Int) = and(b1, notInt(b2))

fun nand(b1: Int,b2: Int) = not(and(b1,b2))

fun nor(b1:Int, b2: Int) = not(or(b1,b2))