<?php
header( "Access-Control-Allow-Origin:*" );
header( "Access-Control-Allow-Methods:POST,GET" );
function FileLastLines($filename,$n){
	  if(!$fp=fopen($filename,'r')){
		      echo "打开文件失败，请检查文件路径是否正确，路径和文件名不要包含中文";
			      return false;
			    }
	    $pos=-2;
	    $eof="";
		  $str="";
		  while($n>0){
			      while($eof!="\n"){
					        if(!fseek($fp,$pos,SEEK_END)){
								        $eof=fgetc($fp);
										        $pos--;
										      }else{
												          break;
														        }
							    }
				      $str.=fgets($fp);
				      $eof="";
					      $n--;
					    }
		    return $str;
}
$s=FileLastLines("./list.txt",1);
//$q=$_GET["timed"];
$s=str_replace(array("\r\n","\r","\n"),"",$s);
#echo $s;
$dataFile=fopen($s,"r");
if($dataFile)
{
#	echo "open";   
	$response=fgets($dataFile);
}
echo $response;
fclose($dataFile);
?>
