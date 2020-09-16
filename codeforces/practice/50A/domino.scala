import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val nm = readLine.split(" ").map(_.toInt)
    val n = nm.head
    val m = nm.last
    println((n*m)/2)
  }
}  
