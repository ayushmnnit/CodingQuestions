package graph

import org.apache.spark.sql.types._
import io.prophecy.libs._
import org.apache.spark._
import org.apache.spark.sql._
import org.apache.spark.sql.functions._
import config.ConfigStore._
import udfs.UDFs._
import udfs._
import graph._

@Visual(id = "CustomerOrdersDatasetOutput", label = "CustomerOrdersDatasetOutput", x = 949, y = 128, phase = 0)
object CustomerOrdersDatasetOutput {

  @UsesDataset(id = "2654", version = 3)
  def apply(spark: SparkSession, in: DataFrame): Target = {
    import spark.implicits._

    Config.fabricName match {
      case "dev" =>
        val schemaArg = StructType(
          Array(
            StructField("order_id",            IntegerType, false),
            StructField("orders",              IntegerType, false),
            StructField("amount",              DoubleType,  false),
            StructField("customer_id",         IntegerType, false),
            StructField("first_name",          StringType,  false),
            StructField("last_name",           StringType,  false),
            StructField("phone",               StringType,  false),
            StructField("email",               StringType,  false),
            StructField("country_code",        StringType,  false),
            StructField("account_length_days", IntegerType, false),
            StructField("account_flags",       StringType,  false)
          )
        )
        in.write
          .format("csv")
          .option("sep", ",")
          .mode("overwrite")
          .save("dbfs:/Prophecy/abhishekvaid@simpledatalabs.com/CustomerOrdersDatasetOutput.csv")
      case _ => throw new Exception("Unknown Fabric")
    }

  }

}
