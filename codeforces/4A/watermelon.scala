import scala.io.StdIn.readInt

object Main {
  def main(args: Array[String]): Unit = {
    val k = readInt;
    if (k > 2 && k%2 == 0) println("YES") else println("NO")  
  }
}
