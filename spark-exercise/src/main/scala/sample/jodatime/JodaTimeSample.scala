package sample.jodatime

import org.joda.time.{DateTime, Hours}

object JodaTimeSample extends App {

  val dt = new DateTime("2017-03-10T23:30:50")
  val recencyBaseTime = new DateTime("2017-03-11T00:00:00")

  val diff = Hours.hoursBetween(dt, recencyBaseTime).getHours

  println(diff)
}
