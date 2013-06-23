<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <title>Twitter List Copy</title>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    <link href="style.css" media="all" rel="stylesheet" type="text/css" />
    <script src="jquery.js" type="text/javascript"></script>
    <script src="listcopy.js" type="text/javascript"></script>
  </head>
  <body>
    <div>
      <h2>Twitter List Copy</h2>
	  <p>Use this ugly-but-functional tool to copy any Twitter list to one of your own.</p>

      <?php print_r($content); ?>

      <hr>
      <?php if (isset($menu)) { ?>
        <?php echo $menu; ?>
      <?php } ?>
    </div>
    <?php if (isset($status_text)) { ?>
      <?php echo '<h3>'.$status_text.'</h3>'; ?>
    <?php } ?>
    
    <?php if($content == "") // this is a super janky test
    {?>
	<div>
		<h2>Copy from</h2>
		<p><label for="source_user">User who owns the list you want to copy: </label><input id="source_user" name="source_user" />
		<input type="button" name="get_source_lists" id="get_source_lists" value="Get lists" /></p>
		<p><label for="source_list">The list you want to copy: </label><select id="source_list" name="source_list"></select></p>
		
		<h2>Copy to</h2>
		<p>Heads up: this will <em>not</em> wipe out a list first, so you should probably create a new list and copy to that. I haven’t tested how it might behave when copying onto a non-blank list. I <em>should</em> merge them, but I don’t know that for sure.</p>
		<p><label for="dest_list">One of your existing lists: </label><select id="dest_list" name="source_list"><? echo $mylists_options; ?></select></p>
		<p><input type="button" name="doCopy" id="doCopy" value="Copy!" /></p>
		<div id="working"></div>

	</div>
    <? } ?>
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
    <hr>
    <div id="footer">
    	<p><a href='./clearsessions.php'>Log out</a>.</p>
		<p>Made by a grad student in his spare time.  <a href="http://tiptheweb.org/tip/" class="ttw-button ttw-button-small">Tip</a> <script src="paypal-button.min.js?merchant=noah@noahliebman.net" 
		    data-button="donate" 
		    data-name="Twitter List Copy" 
		    data-size="small"
		    data-callback="http://projects.noahliebman.net/listcopy/" data-env="sandbox"></script>
		</p>
		<p>Make this better on <a href="https://github.com/Noleli/listcopy">Github</a>.</p>
		<p>A <a href="http://twitter.com/Noleli">Noleli</a>/<a href="http://noahliebman.net">.nl</a> production.</p>
	</div>
	
	
	<!-- Start of StatCounter Code -->
	<script type="text/javascript">
	var sc_project=6325636; 
	var sc_invisible=1; 
	var sc_security="86a49f2d"; 
	</script>
	
	<script type="text/javascript"
	src="http://www.statcounter.com/counter/counter_xhtml.js"></script><noscript><div
	class="statcounter"><a title="weebly reliable statistics"
	class="statcounter"
	href="http://statcounter.com/weebly/"><img
	class="statcounter"
	src="http://c.statcounter.com/6325636/0/86a49f2d/1/"
	alt="weebly reliable statistics" /></a></div></noscript>
	<!-- End of StatCounter Code -->
	
	<!-- Start TipTheWeb code -->
	<script>
		(function (window, document) {
		    var ref = document.getElementsByTagName('script')[0],
		        script = document.createElement('script'),
		        secure = window.location.protocol === 'https:';
		    script.async = true;
		    script.src = secure ? 'https://secure-platform.tiptheweb.org/tip/button.js'
		                        : 'http://platform.tiptheweb.org/tip/button.js';
		    ref.parentNode.insertBefore(script, ref);
		}(this, this.document));
	</script>
	<!-- End TipTheWeb code -->

	<script src="paypal-button.min.js" type="text/javascript"></script>
	
  </body>
</html>
