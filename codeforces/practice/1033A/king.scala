import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt
    val q1q2 = readLine.split(" ").map(_.toInt)
    val q1 = q1q2.head
    val q2 = q1q2.last
    val k1k2 = readLine.split(" ").map(_.toInt)
    val k1 = k1k2.head
    val k2 = k1k2.last
    val t1t2 = readLine.split(" ").map(_.toInt)
    val t1 = t1t2.head
    val t2 = t1t2.last
    if ( ( ( (k1 < q1) && (t1 < q1)  ) || ( (k1 > q1) && (t1 > q1) ) ) && ( ( (k2 < q2) && (t2 < q2) ) || ( (k2 > q2) && (t2 > q2) )) ) println("YES") else println("NO") 
  }
}
