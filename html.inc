<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <title>Twitter List Copy</title>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    <script src="jquery.js" type="text/javascript"></script>
    <script src="listcopy.js" type="text/javascript"></script>
  </head>
  <body>
    <div>
      <h2>Twitter List Copy</h2>

      <p>If you are having issues try <a href='./clearsessions.php'>clearing your session</a>.</p>

      <?php print_r($content); ?>

      <hr />
      <?php if (isset($menu)) { ?>
        <?php echo $menu; ?>
      <?php } ?>
    </div>
    <?php if (isset($status_text)) { ?>
      <?php echo '<h3>'.$status_text.'</h3>'; ?>
    <?php } ?>
	<div>
		<h2>Copy from</h2>
		<p><label for="source_user">User who owns the list you want to copy: </label><input id="source_user" name="source_user" />
		<input type="button" name="get_source_lists" id="get_source_lists" value="Get lists" /></p>
		<p><label for="source_list">The list you want to copy: </label><select id="source_list" name="source_list"></select></p>
		
		<h2>Copy to</h2>
		<p>Heads up: this will <em>not</em> wipe out a list first, so you should probably create a new list and copy to that.</p>
		<p><label for="dest_list">One of your existing lists: </label><select id="dest_list" name="source_list"><? echo $mylists_options; ?></select></p>
		<p><input type="button" name="doCopy" id="doCopy" value="Copy!" /></p>
		<div id="working"></div>

	</div>
    
    <!--<p>
      <pre>
        <?php
        	//print_r($members);
        	//var_dump($add_result);
        	//print_r($content);
        	//echo $cursor;
        ?>
      </pre>
    </p>-->

  </body>
</html>
