import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val knw = readLine.split(" ").map(_.toInt)
    val k = knw.head
    val w = knw.last
    val n = knw(1)
    val total = ((w*(w+1))*k)/2
    if (total > n) println(total-n) else println(0)
  }
}
