<?php
if($_SERVER["argc"]>1)
  $server_path=$_SERVER["argv"][1];
else
  $server_path=".";

echo <<<END
<html><head><title>GMSH/DG validation</title></head>
<style>

END;
include("benchmarks.css");
echo <<<END
</style>
<body>
<h3><a href="$server_path/index.php">GMSH/DG automatic testing report</a></h3>
<table class="slim_validation_table">
<tr class="odd_line">
  <th class="first_col">test name</th>
  <th>status</th>
  <th>last tested</th>
  <th>last passed</th>
  <th>first failed</th>
  <th>time</th>
	<th>diff</th>
</tr>
END;
  function read_file($filename){
    if(file_exists($filename)){
      $fh=fopen($filename,'r');
      fscanf($fh,"%s",$r);
      fclose($fh);
      return $r;
    }else{
      return "none";
    }
  }
  function print_with_log($rev,$log){
    global $server_path;
    if(file_exists($log)){
      echo "  <td><a href=$server_path/$log>$rev</a></td>\n";
    }else{
      echo "  <td>$rev</td>\n";
    }
  }
  $dir=opendir("results");
  $all_test=scandir("results");
  natcasesort($all_test);
  foreach ($all_test as $test) {
    if($test!="." && $test!=".."){
      $status=read_file("results/".$test."/status",'r');
      $last_tested=read_file("results/".$test."/last_tested",'r');
      $last_passed=read_file("results/".$test."/last_passed",'r');
      $first_failed=read_file("results/".$test."/first_failed",'r');
      $time=read_file("results/".$test."/time",'r');
      if($i%2==0)
        echo"<tr class=\"even_line\">\n";
      else
        echo"<tr class=\"odd_line\">\n";
			if(file_exists("results/".$test."/datafile")){
				echo "  <td class=\"first_col\"><a href=$server_path/results/$test/datafile>$test</a></td>\n";
      }else{
				echo "  <td class=\"first_col\">$test</td>\n";
      }
      echo "  <td class=\"slim_benchmark_$status\">$status</td>\n";
      print_with_log($last_tested,"results/$test/log");
      print_with_log($last_passed,"results/$test/log_last_passed");
      print_with_log($first_failed,"results/$test/log_first_failed");
      echo "<td>".$time."</td>\n";
			echo "<td>\n";
			if($first_failed!="none" && $last_passed!="none"){
			echo "<a href=\"https://geuz.org/trac/gmsh/changeset?old_path=/trunk&old=$last_passed&new_path=/trunk&new=$first_failed\">$last_passed:$first_failed</a>";
			}
			echo "</td>\n";
      echo "</tr>\n";
    }
  }
echo <<<END
</table>
</body>
</html>
END
?>
