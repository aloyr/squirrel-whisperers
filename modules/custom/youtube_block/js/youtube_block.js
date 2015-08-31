/**
 * @file
 * Main JavaScript file for the youtube_block module.
 */

Drupal.behaviors.youtube_block = {
    attach: function (context, settings) {

        // Initiate each Youtube instance
        jQuery('div.youtube').each(function (index) {

            // Overlay the play icon to make it look like a video player
            jQuery(this).append('<div class="play"></div>');

            // Attach a click event to the Youtube thumbnail
            // and load the video
            jQuery(this).click(function () {
                var thumbnail = jQuery(this).children('img'),
                    videoID = thumbnail.attr('id'),
                      width = thumbnail.width(),
                     height = thumbnail.height(),
                     iframe = jQuery('<iframe />', {
                        name: thumbnail,
                        width: width,
                        height: height,
                        src: 'https://www.youtube.com/embed/' + videoID
                        + '?autoplay=1&autohide=1&border=0&wmode=opaque'
                    });

                // Replace the thumbnail with the iframe
                jQuery(this).html(iframe);

            });

        });

    }
};