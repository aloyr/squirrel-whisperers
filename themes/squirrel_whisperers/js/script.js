/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */


(function ($, Drupal, window, document, undefined) {

Drupal.behaviors.squirrel_whisperers = {
  attach: function(context, settings) {

      //Track whether modal is visible
      var counter = 0;
      //Add modal box and play a song
      function addModal(event, song, album, albumCover, buyItNow, trackNumber, trackPreview) {
          if (counter != 1) {
              var makeDiv = document.createElement('div');
              makeDiv.className = 'table-size';
              var overlayDiv = document.createElement('div');
              overlayDiv.className = 'table-size-overlay';
              overlayDiv.innerHTML += "<span class='img'><img src=" + albumCover + "></span>";
              overlayDiv.innerHTML += "<label>Rows<input type='text' id='ht-rows' name='rows' value='0' maxlength='3'></label> x ";
              overlayDiv.innerHTML += "<label>Columns<input type='text' id='ht-cols' name='cols' value='0' maxlength='3'></label>";
              overlayDiv.innerHTML += "<a href='#close' class='btn table-size-close' data-action='closeModal'>Cancel</a>";
              makeDiv.appendChild(overlayDiv);
              jQuery('ul.discography-songs').prepend(makeDiv);
              counter++;
          }
      }

      function removeModal() {
          //Remove modal box
          if (counter == 1) {
              jQuery('div.table-size').remove();
              counter = 0;
          }
      }

      var actions = {
          showModal: function (event, song, album, albumCover, buyItNow, trackNumber, trackPreview) {
              addModal(event, song, album, albumCover, buyItNow, trackNumber, trackPreview);
          },
          closeModal: removeModal
      };

      jQuery(document.body).delegate('ul.discography-songs a[data-action]', 'click', function (event) {
          var $this = jQuery(this),
              action = $this.data('action'),
              song = $this.val(),
              album = $this.data('album'),
              albumCover = $this.data('album-cover'),
              buyItNow = $this.data('buy-it-now'),
              trackNumber = $this.data('track-number'),
              trackPreview = $this.data('track-preview');

          event.preventDefault();

          // If there's an action with the given name, call it
          if (typeof actions[action] === 'function') {
              actions[action].call(this, event, song, album, albumCover, buyItNow, trackNumber, trackPreview);
          }
      });

  }
};

})(jQuery, Drupal, this, this.document);
