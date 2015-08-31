/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */
(function($, Drupal, window, document, undefined) {

    Drupal.behaviors.squirrel_whisperers = {
        attach: function(context, settings) {

            //Track whether modal is visible
            var counter = 0;
            //Add modal box and play a song
            function addModal(event, song, album, albumCover, buyItNow, trackNumber, trackPreview) {
                if (counter != 1) {
                    var makeDiv = document.createElement('div');
                    makeDiv.className = 'modal-overlay';
                    var overlayDiv = document.createElement('div');
                    overlayDiv.className = 'modal-container';
                    overlayDiv.innerHTML += '<a href="#close" class="close" data-action="closeModal"> X </a>';
                    overlayDiv.innerHTML += '<div class="album-cover"><img src="' + albumCover + '"></div>';
                    overlayDiv.innerHTML += '<div class="track-info"><h3>' + song + '</h3><h4>' + album + '</h4></div>';
                    overlayDiv.innerHTML += '<a href="' + buyItNow + '" class="btn" target="_blank">Buy on iTunes</a>';
                    overlayDiv.innerHTML += '<div class="player"><audio src="' + trackPreview + '" controls>' + '<p>Your browser does not support the audio element</p></audio></div>';
                    makeDiv.appendChild(overlayDiv);
                    jQuery('ul.discography-songs').prepend(makeDiv);
                    counter++;
                }
            }

            function removeModal() {
                //Remove modal box
                if (counter == 1) {
                    jQuery('div.modal-overlay').remove();
                    counter = 0;
                }
            }

            var actions = {
                showModal: function(event, song, album, albumCover, buyItNow, trackNumber, trackPreview) {
                    addModal(event, song, album, albumCover, buyItNow, trackNumber, trackPreview);
                },
                closeModal: removeModal
            };

            // Trigger for click events so we can play the song
            jQuery(document.body).delegate('ul.discography-songs a[data-action]', 'click', function(event) {
                var $this = jQuery(this),
                    action = $this.data('action'),
                    song = $this.data('track'),
                    trackNumber = $this.data('track-number'),
                    trackPreview = $this.data('track-preview'),
                    album = $this.data('album'),
                    albumCover = $this.data('album-cover'),
                    buyItNow = $this.data('buy-it-now');

                event.preventDefault();

                // If there's an action with the given name, call it
                if (typeof actions[action] === 'function') {
                    actions[action].call(this, event, song, album, albumCover, buyItNow, trackNumber, trackPreview);
                }
            });

            // Show the fixed menu when the user scrolls past main nav
            jQuery(window).bind('scroll', function() {
                if (jQuery(window).scrollTop() > 167) {
                    jQuery('#fixed-menu').show();
                } else {
                    jQuery('#fixed-menu').hide();
                }
            });

            // Scroll animation effect
            jQuery('.main-nav a').click(function(event) {
                event.preventDefault();
                var targetID = jQuery(this).attr('href'),
                    hash = '#' + targetID.substring(targetID.indexOf('#')+1),
                    target = jQuery(hash).offset().top - 54;
                jQuery('body, html').animate({
                    scrollTop: target + 'px'
                }, 300);
            });

        }
    };

})(jQuery, Drupal, this, this.document);