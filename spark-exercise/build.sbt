name := "spark-sample"

version := "1.0"

scalaVersion := "2.11.4"

libraryDependencies ++= Seq(
  "org.apache.spark"  %% "spark-core"           % "2.1.0"          % "provided",
  "org.apache.spark"  %% "spark-sql"            % "2.1.0"          % "provided",
  "org.apache.spark"  %% "spark-mllib"          % "2.1.0"          % "provided",
  "org.scalanlp"      %% "breeze"               % "0.13",
  "postgresql"         % "postgresql"           % "8.4-702.jdbc4",
  "mysql"              % "mysql-connector-java" % "5.1.26",
  "joda-time"          % "joda-time"            % "2.4",
  "org.joda"           % "joda-convert"         % "1.7",
  "org.apache.commons" % "commons-math3"        % "3.6.1"
)
    
