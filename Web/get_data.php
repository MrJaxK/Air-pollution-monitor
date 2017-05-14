<?php
	error_reporting(0);                                  
    ini_set('date.timezone','Asia/Shanghai');
	$output=date('[Y-m-d H:i:s]',time())." ";
	//echo "123";
	for($j=0;$j<2;$j++)
	 {echo $j;}
    for($i=0;$i<9;$i++)
		    {
				        $output.=$_GET[$i+""];
						echo $i;
						$output.=" ";
						    }
	    $StrDate=date('[Y-m-d H:i:s]',time());
	$datafile=fopen($StrDate,"w");
	$output.="\n";
	fwrite($datafile,$output);
    fclose($datafile);
	$listFile=fopen("list.txt","a");
	$StrDate.="\n";
    fwrite($listFile,$StrDate);
	fclose($listFile);
?>

