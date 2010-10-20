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
      <h2>Welcome to a Twitter OAuth PHP example.</h2>

      <p>This site is a basic showcase of Twitters OAuth authentication method. If you are having issues try <a href='./clearsessions.php'>clearing your session</a>.</p>

      <p>
        Links:
        <a href='http://github.com/abraham/twitteroauth'>Source Code</a> &amp;
        <a href='http://wiki.github.com/abraham/twitteroauth/documentation'>Documentation</a> |
        Contact @<a href='http://twitter.com/abraham'>abraham</a>
	  </p>
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
		<input id="source_user" name="source_user" />
		<input type="button" name="get_source_lists" id="get_source_lists" value="Get lists" />
		<select id="source_list" name="source_list"></select>
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
