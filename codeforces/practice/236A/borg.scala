import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val s = readLine
    if (s.toSeq.distinct.size % 2 == 0) println("CHAT WITH HER!") else println("IGNORE HIM!")
  }
}
